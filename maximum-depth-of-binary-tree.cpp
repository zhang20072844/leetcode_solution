/************************************************************************
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

************************************************************************/

//solution
//not so good
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
	int theMaxDepth = 0;
	void getMaxDepth(TreeNode *root, int deep)
	{
		if (root->left == NULL && root->right == NULL)
		{
			if (deep > theMaxDepth)
				theMaxDepth = deep;
		}
		if (root->left != NULL)
		{
			getMaxDepth(root->left, deep+1);
		}
		if (root->right != NULL)
		{
			getMaxDepth(root->right, deep+1);
		}
	}
	int maxDepth(TreeNode *root) {
		theMaxDepth = 0;
		if (root == NULL)
			return 0;
		getMaxDepth(root, 1);
		return theMaxDepth;
	}
};