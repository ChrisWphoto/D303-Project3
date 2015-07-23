#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "BST.h"
using namespace std;


int main(){

	//open file stream for morse.txt
	ifstream fin("morse.txt");

	//declare new empty tree with one BTNode
	BST tree;

	tree.make_morse_tree(fin);
	

	//send in file to decode into english
	ifstream ffin("decode.txt");
	cout << tree.decode_morse(ffin);
	
	//can accept strings only, this will cause an error b/c its too long
	string letter = "__...";
	cout << tree.decode_morse(letter);

	letter = letter.substr(1);
	return 0;
}