/************************************************************************
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
************************************************************************/

//solution
//

#include <iostream>
#include <string>
using namespace std;

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	int theMinDepth = 0x7FFFFFFF;
	void getMinDepth(TreeNode *root, int deep)
	{
		if (root->left == NULL && root->right == NULL)
		{
			if (deep < theMinDepth)
				theMinDepth = deep;
		}
		if (root->left != NULL)
		{
			getMinDepth(root->left, deep+1);
		}
		if (root->right != NULL)
		{
			getMinDepth(root->right, deep+1);
		}
	}
	int minDepth(TreeNode *root) {
		int deep = 1;
		if (NULL == root)
		{
			return 0;
		}
		getMinDepth(root, deep);
		return theMinDepth;
	}
};


//recurve
int minDepth(TreeNode *root) {
	int deep = 1;
	if (NULL == root)
	{
		return 0;
	}
	if (root->left == NULL && root->right==NULL)
	{
		return 1;
	}
	int l = 0;
	int r = 0;

	//if (root->left != NULL)
	{
		l = minDepth(root->left);
	}
	// if (root->right != NULL)
	{
		r = minDepth(root->right);
	}

	if (l>0&&r>0)return (l<r?l:r)+1;
	return l+r+1;
}