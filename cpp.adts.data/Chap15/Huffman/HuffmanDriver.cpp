
//--- Driver Program ---
#include "Huffman"
#include <iostream>
#include <fstream>

int main()
{
  char filename[32];
  cout << "Enter name of code file: ";  cin >> filename;
  ifstream codestream(filename);
  if (!codestream.is_open())
  {
    cout << "Cannot open code file.\n";
    exit(-1);
  }

  Huffman h;
  h.BuildDecodingTree(codestream);
  h.DisplayDecodingTree(cout);
  cout << endl << endl;
  
  cout << "Enter name of message file: ";  cin >> filename;
  ifstream message(filename);
  if (!message.is_open())
  {
    cout << "Cannot open message file.\n";
    exit(-1);
  }
  h.Decode(message);
}
