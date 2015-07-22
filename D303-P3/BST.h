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

	BTNode* root;
	BST(BTNode* new_root)
	{
		root = new_root;
	}

	string find(BTNode* local_root, const string& target);
	

	bool insert(BTNode*& local_root, const map<string, char>::iterator& item);
	
};


#endif
