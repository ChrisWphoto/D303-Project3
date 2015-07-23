#include <string>
#include <map>
using namespace std;

#ifndef BST_H
#define BST_H

class BST 
{
public:

	struct BTNode
	{
		string dataKey;
		string dataValue;
		BTNode* left;
		BTNode* right;

		BTNode()
		{
			dataKey = "";
			dataValue = "";
			left = nullptr;
			right = nullptr;
		}
		
		virtual ~BTNode() {}
	};

	//data
	BTNode* root;
	
	//default Constructor
	BST() {	root = new BTNode(); }

	//constructor
	BST(BTNode* new_root) { root = new_root; }

	string find(BTNode* local_root, const string& target);
	bool insert(BTNode*& local_root, const map<string, char>::iterator& item);


	//Make the Morse Code Tree
	void make_morse_tree(ifstream& fin);

	//Insert from file 
	void insert_with_code(string& letter_code, int idx, BTNode*& local_root,
		char& letter);

	//Decode from file, parser
	string decode_morse(ifstream& fin);

	//decode from string, parser
	string decode_morse(string code);

	//decoding method
	string decoding(BTNode* local_root, string letter);

	//in-order traverse wrapper
	string in_order() ;

	//in-order recursive function
	void in_order_recursive(string& result, BTNode*& local_root) ;

	
};


#endif
