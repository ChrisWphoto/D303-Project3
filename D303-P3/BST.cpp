#include "BST.h"

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
