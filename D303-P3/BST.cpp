#include "BST.h"
#include <fstream>
#include <sstream>
bool BST::insert(BTNode*& local_root, const map<string,char>::iterator& item)
{
	if (local_root == NULL)
	{
		local_root = new BTNode();
		local_root->dataKey = item->first;
		local_root->dataValue = item->second;
		return true;
	}
	else
	{
		if (local_root->dataKey > item->first)
			return insert(local_root->left, item);
		else if (local_root->dataKey < item->first)
			return insert(local_root->right, item);
		else
			return false;
	}
}
string BST::find(BTNode* local_root, const string& target)
{
	if (local_root == NULL)
		return NULL;
	if (local_root->dataKey > target)
		return find(local_root->left, target);
	else if (local_root->dataKey < target)
		return find(local_root->right, target);
	else
		return local_root->dataValue;
}

//
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
	if (!fin.good())
	{
		return "The file can not be opened";
	}
	stringstream buffer;
	buffer << fin.rdbuf();
	string code_to_decipher, decoded = "";

	while (buffer >> code_to_decipher)
	{
		decoded += decoding(root, code_to_decipher);
	}

	return decoded;
}

//overloaded to accept plain string code
string BST::decode_morse(string code)
{
	stringstream buffer(code);
	string code_to_decipher, decoded = "";

	while (buffer >> code_to_decipher)
	{
		decoded += decoding(root, code_to_decipher);
	}

	return decoded;

}

//the searching portion
string BST::decoding(BTNode* root,  string letter)
{
	string error;
	//check to see if there is a tree ready	
	if (root == NULL)
	{
		error = "The tree is empty! Be sure to populate the data first";
		return error;
	}
	if (letter.empty())
	{
		error = "There needs to be a code to decode!";
		return error;
	}
	char step;
	BTNode * current = root;
	for (int i = 0; i < letter.size(); i++)
	{
		
		step = letter[i];
		switch (step)
		{
		case '.':
			if (current->left == NULL){return " The code is too long";}
			current = current->left;
			break;
		case '_':
			if (current->right == NULL){return " The code is too long";}
			current = current->right;
			break;
		default:
			error = string(" Error: Character, ") + step + (" is not recognized.");
			return error;
		}
	}
	return current->dataKey;
	
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