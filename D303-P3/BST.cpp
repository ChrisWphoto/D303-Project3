#include "BST.h"
#include <iostream>
#include <fstream>
#include <sstream>

BST::BST()
{
	root = new BTNode();
	// map for encoding english -> morse code
	encoder["._"] = 'a';
	encoder["_..."] = 'b';
	encoder["_._."] = 'c';
	encoder["_.."] = 'd';
	encoder["."] = 'e';
	encoder[".._."] = 'f';
	encoder["__."] = 'g';
	encoder["...."] = 'h';
	encoder[".."] = 'i';
	encoder[".____"] = 'j';
	encoder["_._"] = 'k';
	encoder["._.."] = 'l';
	encoder["__"] = 'm';
	encoder["_."] = 'n';
	encoder["___"] = 'o';
	encoder[".__."] = 'p';
	encoder["__._"] = 'q';
	encoder["._."] = 'r';
	encoder["..."] = 's';
	encoder["_"] = 't';
	encoder[".._"] = 'u';
	encoder["..._"] = 'v';
	encoder[".__"] = 'w';
	encoder["_.._"] = 'x';
	encoder["_.__"] = 'y';
	encoder["__.."] = 'z';
	}


void BST::make_morse_tree(ifstream& fin){
	string letter_code;
	while (fin >> letter_code){
		char letter = letter_code[0]; //store letter for eventual insertion
		insert_with_code(letter_code, 1, root, letter);
	}
}


void BST::insert_with_code(string& letter_code, int idx, BTNode*& local_root,
	char& letter){
	if (idx == letter_code.length() + 1) //one past the end of the code
		return;
	
	if (local_root == nullptr) //need to creat a empty BTNode
		local_root = new BTNode();
	
	if (idx != letter_code.length()){ //still need to find location

		if (letter_code[idx] == '.') //go left
			insert_with_code(letter_code, idx + 1, local_root->left, letter);
		else //go right
			insert_with_code(letter_code, idx + 1, local_root->right, letter);
	}

	else //time for insertion of letter
		local_root->dataKey = letter; 

}

//the parser for reading from file
string BST::decode_morse(ifstream& fin)
{
	if (!fin.good()){
		return "ERROR: The file cannot be opened";
	}
	stringstream buffer;
	buffer << fin.rdbuf();
	string code_to_decipher, decoded = "";

	while (buffer >> code_to_decipher){
		decoded += " " + decoding(root, code_to_decipher);
	}

	return decoded;
}

//overloaded to accept plain string code
string BST::decode_morse(string code)
{
	stringstream buffer(code);
	string code_to_decipher, decoded = "";

	while (buffer >> code_to_decipher){
		decoded += " " + decoding(root, code_to_decipher);
	}

	return decoded;

}

//the searching portion
string BST::decoding(BTNode* root,  string letter)
{
	//check to see if there is a tree ready	
	if (root == NULL){
		return  "ERROR: The tree is empty! Be sure to populate the data first";
	}
	if (letter.empty()){
		return "ERROR: There needs to be a code to decode!";
	}
	char step;
	BTNode * current = root;
	for (int i = 0; i < letter.size(); i++){
		step = letter[i];
		switch (step){
		case '.':
			if (current->left == NULL){return "ERROR: The code \""+letter+"\" is too long";}
			current = current->left;
			break;
		case '_':
			if (current->right == NULL){return "ERROR: The code \"" + letter + "\" is too long";}
			current = current->right;
			break;
		default:
			return string(" ERROR: Character, ") + step + " is not recognized.";
		}
	}
	return current->dataKey;
	
}

// encoder
string BST::encode(string code)
{
	string encodedValue = "";
	for (int i = 0; i < code.size(); i++)
	{
		if (code[i] == ' ')
		{
			continue;//if there's a space then we will skip it to the next letter
		}
		else
		{
			for (map<string, char>::iterator it = encoder.begin(); it != encoder.end(); ++it) 
			{
				// iterate through map until you find the english character, then append the respective morse code
				if (it->second == code[i])
				{
					encodedValue += it->first + " ";
					break;
				}
			}
		}
	}
	return encodedValue;
}

//in-order traverse wrapper
string BST::in_order() {
	string result;
	in_order_recursive(result, root);
	return result;
}

//in-order recursive function
void BST::in_order_recursive(string& result, BTNode*& local_root) {
	if (local_root != nullptr){
		in_order_recursive(result, local_root->left);
		result += local_root->dataKey;
		in_order_recursive(result, local_root->right);

	}
}