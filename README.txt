README

Assignment 2: Restriction Enzyme - BST vs AVL trees
CSCI335-01
Shu Xin Lei

Overview:
The purpose of this assignment be comfortable with binary search trees and self-balancing AVL trees. Here, I was able to analyze and compare the performance of between the two. By using real world data set, I was able to construct a generic test routine to compare different implementations of the tree container class. 

The zip file contains the necessary components to run the program: 
AvlTree.h
BinarySearchTree.h
dsexceptions.h
query_tree.cc
SequenceMap.cpp
SequenceMap.h
text_tree.cc
Makefile 

It also includes the following input/output file:
input_part2a.txt
rebase210.txt
sequences.txt


To compile on terminal type
  make all

To delete executables and object file type
  make clean

To run part 2a:
  ./query_tree rebase210.txt BST < input_part2a.txt
  ./query_tree rebase210.txt AVL < input_part2a.txt

To run part 2b:
  ./test_tree rebase210.txt sequences.txt BST
  ./test_tree rebase210.txt sequences.txt AVL

Issues: 
I ran into a couple of compilation errors. For example, I wasn't able to create a remove function that return a bool. I decided to pass by parameter a bool object instead that holds whether the remove was successful. Also the numbers are not exactly the same as the output. However, the process in achieving the numbers should be correct.


