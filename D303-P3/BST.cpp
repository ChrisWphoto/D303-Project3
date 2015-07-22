#include "BST.h"
#include <fstream>
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