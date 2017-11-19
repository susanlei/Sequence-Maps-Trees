// Shu Xin Lei
// Main file for Part2(a) of Homework 2.

#include "AvlTree.h"
#include "BinarySearchTree.h"
#include "SequenceMap.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

namespace {

// @db_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void QueryTree(const string &db_filename, TreeType &a_tree) {
  // Code for running Part2(a)

  // Open file
  ifstream fin;
  fin.open(db_filename);
  if (!fin) { //test if file is openable
    cout << "Unable to open file" << endl;
  }

  string db_line; 

  if (db_filename == "rebase210.txt") {
    //rid the header of the file
    for (int i = 0; i < 10; ++i) {
      getline(fin, db_line);
    }

    // Start to set and store the sequence itself
    while(getline(fin, db_line)) {
      if (db_line.empty()) {
        break;
      } 

      stringstream ss(db_line); 
      string enzAcro;
      getline(ss, enzAcro, '/'); // Store enzyme only

      string recSeq;
      while(getline(ss, recSeq, '/')) { // Store recognition sequence
        if (recSeq != "") { // If the recognition sequence is NOT empty
          SequenceMap tempSequenceMap(recSeq, enzAcro);
          a_tree.insert(tempSequenceMap);
        }      
      }
    } 
  }

  if (db_filename == "sequences.txt") { //file contains only sequences
    // Start to set and store the sequence itself 
    while(getline(fin, db_line)) {
      SequenceMap tempSequenceMap(db_line);
      a_tree.insert(tempSequenceMap);
    }
  }

  fin.close();


  // Take in sequences from user
  string userSequence;
  cout << "Please enter 'EXIT' to exit" << endl;
  while (getline(cin, userSequence)) { 
    if (userSequence != "EXIT") {
      if (!a_tree.contains(userSequence)) {
        cout << "Not Found" << endl;
      }
      else { // Find sequence and print out the enzyme acronym 
        a_tree.search(userSequence);
      }    
    }
    else if (userSequence == "EXIT") {
      break;
    }
  }

  // You can use public functions of TreeType. For example:
  //a_tree.insert(10);
  //a_tree.printTree();

} // QueryTree

}  // namespace

int
main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <databasefilename> <tree-type>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  const string param_tree(argv[2]);
  cout << "Input filename is " << db_filename << endl;
  cout << "Type of tree is " << param_tree << endl;
  if (param_tree == "BST") {
    // Note that you will replace BinarySearchTree<int> with BinarySearchTree<SequenceMap>
    BinarySearchTree<SequenceMap> a_tree;
    QueryTree(db_filename, a_tree);
  }  
  else if (param_tree == "AVL") {
    // Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
    AvlTree<SequenceMap> a_tree;
    QueryTree(db_filename, a_tree);
  } 
  else {
    cout << "Uknown tree type " << param_tree << " (User should provide BST, or AVL)" << endl;
  }
  return 0;
}
