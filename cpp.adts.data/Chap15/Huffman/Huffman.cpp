#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#ifndef HUFFMAN
#define HUFFMAN

class Huffman
{
private:
/*** Node structure ***/
struct BinNode
{
  char data;
  BinNode * left,
          * right;

  // BinNode constructor
  BinNode(char item)
  {
    data = item;
    left = right = 0;
  }
};

typedef BinNode * BinNodePointer;

/*** Function members ***/
public:
/* Constructor
 *  Precondition:  A Huffman object has been declared.
 *  Postcondition: One-node binary tree with root node
 *                 pointed to by root has been created.
 ******************************************************************/
Huffman();

/* Build the Huffman decoding tree.
 *  Receive:       Huffman object containing this function (implicitly)
 *                 fstream in
 *  Input:         Characters and their codes via in.
 *                 Last line of code file must contain *. 
 *  Postcondition: Huffman decoding tree has been created with root
 *                 node pointed to by root.
 ******************************************************************/
void BuildDecodingTree(ifstream & CodeFile);

/* Insert a node for a character in Huffman decoding tree.
 *  Receive:       char c and code, a bit string
 *  Postcondition: Node containing c has been inserted into
 *                 Huffman tree with root pointed to by root.
 ******************************************************************/
void Insert(char ch, string code);

/* Read a message (string of bits) from a file and decode it
 * using the huffman decoding tree.
 *  Receive:   Huffman object containing this function (implicitly)
 *             fstream in connected to message file
 *  Input:     Message via in
 *             Last line of message file must contain *.
 *  Output:    Decoded message
 ******************************************************************/
void Decode(ifstream & in);

/* --- A binary tree printer
 * Displays a binary tree recursively.  The tree is displayed
 * "on its side" with each level  indented by a specified value
 * Indent, but with  no arcs sketched in.
 *  Receive: Root of binary tree and integer indent
 *  Output:  Graphical representation of the binary tree
 ******************************************************************/
void PrintTree(ostream & out, BinNodePointer root, int indent);

/* Display the decoding tree
 *  Receive: Huffman object containing this function (implicitly)
 *           ostream out
 *  Output:  The decoding tree via PrintTree()
 ******************************************************************/
void DisplayDecodingTree(ostream & out);

/*** Data members ***/
private:
  BinNodePointer root;
};

//--- Definition of consructor
inline Huffman::Huffman()
{ root = new BinNode('*'); }

//--- Definition of BuildDecodingTree()
void Huffman::BuildDecodingTree(ifstream & in)
{
  char ch;          // a character
  string code;      // its code
  for (;;)
  {
    in >> ch >> code;
    if (ch == '*') return;
    Insert(ch, code);
  }
}

//--- Definition of Insert()
void Huffman::Insert(char ch, string code)
{
  Huffman::BinNodePointer p = root;   // pointer to move down the tree

  for(int i = 0; i < code.length(); i++)
  {
    switch (code[i])
    {
      case '0' :           // descend left
        if (p->left == 0)  // create node along path
          p->left = new Huffman::BinNode('*');
        p = p->left;
        break;

      case '1' :           // descend right
        if (p->right == 0) // create node along path
          p->right = new Huffman::BinNode('*');
        p = p->right;
        break;

      default:
        cout << "*** Illegal character in code ***\n";
        exit(-1);
    }
  }
  p->data = ch;
}

//--- Definition of Decode()
void Huffman::Decode(ifstream & in)
{
  char bit;                  // next message bit
  Huffman::BinNodePointer p; // pointer to trace path in decoding tree

  for(;;)
  {
    p = root;
    while (p->left != 0 || p->right != 0)
    {
      in >> bit;
      if (bit == '*') return;
      cout << bit;
      if (bit == '0')
        p = p->left;
      else if (bit == '1')
        p = p->right;
      else
        cout << "Illegal bit: " << bit << " -- ignored\n";
    }
    cout << "--" << p->data << endl;
  }
}

//--- Definition of PrintTree()
void Huffman::PrintTree(ostream & out, Huffman::BinNodePointer root,
                        int indent)
{
  if (root != 0)
  {
    PrintTree(out, root->right, indent + 8);
    out << setw(indent) << " " << root->data << endl;
    PrintTree(out, root->left, indent + 8);
  }
}

//--- Definition of DisplayDecodingTree()
inline void Huffman::DisplayDecodingTree(ostream & out)
{ PrintTree(out, root, 0); }

#endif
