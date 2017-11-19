// <Your name>
// Main file for Part2(b) of Homework 2.

#include "AvlTree.h"
#include "BinarySearchTree.h"
#include "SequenceMap.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

namespace {

// @db_filename: an input database filename.
// @seq_filename: an input sequences filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void TestTree(const string &db_filename, const string &seq_filename, TreeType &a_tree) {
  // Code for running Part2(a)

  // Open file & Parse 
  ifstream fin;
  fin.open(db_filename);
  if (!fin) { //test if file is openable
    cout << "Unable to open file" << endl;
  }

  string db_line; 

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

  fin.close();
  //End of parse function

  // Part 2B 
  cout << "2. " << a_tree.numOfNodes() << endl; // Print the number of nodes in the tree

  float avgDepth = a_tree.numOfPaths()/a_tree.numOfNodes(); // Calculate the average depth of tree
  cout << "3a. " << avgDepth << endl;
  cout << "3b. " << avgDepth/log2(a_tree.numOfNodes()) << endl; // Print the ratio of the average depth to log2n


  // Dealing with the sequence.txt file in part 4
  fin.open(seq_filename);
  if (!fin) { // test if file is openable
    cout << "Unable to open sequence file" << endl;
  }

  string seqLine;
  int successfulQueries = 0;
  int numOfQueries = 0;
  float recursionCalls = 0.00;

  while(getline(fin, seqLine)) {
    numOfQueries++; // Total number of queries in sequence.txt file
    SequenceMap tempSequenceMap(seqLine);

    if (a_tree.contains(tempSequenceMap, recursionCalls)) { // Calculate successful queries for 4a
      successfulQueries++;
    }

  } // end of while loop
  fin.close(); // close sequence.txt file

  cout << "4a. " << successfulQueries << endl; // Print the total number of successful queries
  float avgRecursionCalls = recursionCalls/numOfQueries; // Calculate the average number of recursion calls 
  cout << "4b. " << avgRecursionCalls << endl; 

  // open sequence.txt file for part 5
  fin.open(seq_filename);
  if (!fin) { //test if file is openable
    cout << "Unable to open sequence file" << endl;
  }

  recursionCalls = 0.00; // Reset the variable for part 5
  int successfulRemoves = 0;
  int numOfRemoves = 0;

  while (getline(fin, seqLine)) {
    numOfRemoves++;
    SequenceMap tempSequenceMap(seqLine);
    bool removedNode = false;
    a_tree.remove(tempSequenceMap, recursionCalls, removedNode);

    if (removedNode) {
      successfulRemoves++; // Count the number of times remove was called
    }
    getline(fin, seqLine); // Get every other sequence in file
  }
  fin.close();

  cout << "5a. " << successfulRemoves << endl; // Print the total number of successful removes
  avgRecursionCalls = recursionCalls/successfulRemoves; // Calculate the average number of recursion calls
  cout << "5b. " << avgRecursionCalls << endl;


  cout << "6a. " << a_tree.numOfNodes() << endl; // Print the number of nodes in the tree
  avgDepth = a_tree.numOfPaths()/a_tree.numOfNodes(); // Calculate the average depth of tree
  cout << "6b. " << avgDepth << endl;
  cout << "6c. " << avgDepth/log2(a_tree.numOfNodes()) << endl; // Print the ratio of the average depth to log2n


} // TestTree bracket
}  // namespace

int
main(int argc, char **argv) {
  if (argc != 4) {
    cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename> <tree-type>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  const string seq_filename(argv[2]);
  const string param_tree(argv[3]);
  cout << "Input file is " << db_filename << ", and sequences file is " << seq_filename << endl;
  cout << "Type of tree is " << param_tree << endl;
  if (param_tree == "BST") {
    // Note that you will replace BinarySearchTree<int> with BinarySearchTree<SequenceMap>
    BinarySearchTree<SequenceMap> a_tree;
    TestTree(db_filename, seq_filename, a_tree);
  } else if (param_tree == "AVL") {
    // Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
    AvlTree<SequenceMap> a_tree;
    TestTree(db_filename, seq_filename, a_tree);
  } else {
    cout << "Uknown tree type " << param_tree << " (User should provide BST, or AVL)" << endl;
  }
  return 0;
}
