/* Huffman.h --------------------------------------------------------------
   Header file for a class Huffman for  Huffman codes.
   Operations are:  A constructor and an output operation.
   -----------------------------------------------------------------------*/

#include <string>
#include <iostream>
#include <fstream>

#ifndef HUFFMAN
#define HUFFMAN

class Huffman
{
 private:
  /*** Node structure ***/
  class BinNode
  {
   public:
    char data;
    BinNode * left,
            * right;

    // BinNode constructor
    BinNode(char item)
    : data(item), left(0), right(0)
    { }
  };

  typedef BinNode * BinNodePointer;

 public:
  /*** Function members ***/
  Huffman();
  /*-----------------------------------------------------------------------
    Constructor
	Precondition:  A Huffman object has been declared.
	Postcondition: One-node binary tree with root node pointed to by
	               root has been created.
    ----------------------------------------------------------------------*/ 

/* Build the Huffman decoding tree.
 *  Receive:       Huffman object containing this function (implicitly)
 *                 fstream in
 *  Input:         Characters and their codes via in.
 *                 Last line of code file must contain *. 
 *  Postcondition: Huffman decoding tree has been created with root
 *                 node pointed to by root.
 ******************************************************************/
void BuildDecodingTree(ifstream & CodeFile);
  /*-----------------------------------------------------------------------
    Build the Huffman decoding tree.
	Precondition:  .
	Postcondition: One-node binary tree with root node pointed to by
	               root has been created.
    ----------------------------------------------------------------------*/ 
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

#endif
