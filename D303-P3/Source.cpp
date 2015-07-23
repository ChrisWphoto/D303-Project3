#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "BST.h"
using namespace std;


int main(){

	//open file stream for morse.txt
	ifstream fin("morse.txt");

	//declare new empty tree and create morse code 
	BST tree;
	tree.make_morse_tree(fin);

	//In-order traverse to check validity
	string in_order_result = tree.in_order();

	//send in file to decode into english
	ifstream ffin("decode.txt");
	cout << tree.decode_morse(ffin) << endl;
	
	//can accept strings only, this will cause an error b/c its too long
	string letter = "__...";
	cout << tree.decode_morse(letter);

	letter = letter.substr(1);

	cout << endl << endl;
	system("pause");
	return 0;
}