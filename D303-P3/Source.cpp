#include <iostream>
#include <fstream>
#include "BST.h"
using namespace std;


int main(){

	//open file stream for morse.txt
	ifstream fin("morse.txt");

	//declare new empty tree with one BTNode
	BST tree;

	tree.make_morse_tree(fin);



	
	return 0;
}