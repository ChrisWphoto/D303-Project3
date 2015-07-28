#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Morse.h"
using namespace std;


int main(){

	//open file stream for morse.txt
	ifstream fin("morse.txt");

	//declare new empty tree and create morse code 
	Morse tree;
	tree.make_morse_tree(fin);
	
	//In-order traverse to check validity
	string in_order_result = tree.in_order();

	//Decode Morse --> English from file
	ifstream ffin("decode.txt");
	cout << "Decoding Morse Code from file: ";
	cout << tree.decode_morse(ffin) << endl;
	

	//Decode Morse --> English from string
	//If string is too long an error will be printed
	string letter = "__..";
	cout << "Decoding the string '" << letter << "': ";
	cout << tree.decode_morse(letter) << endl;

	//Encoding English --> Morse
	string engLetter = "hello there";
	string encoded = tree.encode(engLetter);
	cout << "Encoding the string: '" << tree.decode_morse(encoded) << "':"<<endl;
	cout << encoded << endl;

	cout << endl << endl;

	system("pause");
	return 0;
}