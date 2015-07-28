#include <string>
#include <map>
using namespace std;

#ifndef Morse_H
#define Morse_H

class Morse 
{
public:

	struct BTNode
	{
		string dataKey;
		BTNode* left;
		BTNode* right;

		BTNode()
		{
			dataKey = "";
			left = nullptr;
			right = nullptr;
		}
		
		virtual ~BTNode() {}
	};

	map<string, char> encoder;

	//data
	BTNode* root;
	
	//default Constructor
	Morse();

	//constructor
	Morse(BTNode* new_root) { root = new_root; }

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

	//encode using map
	string encode(string code);
};


#endif
