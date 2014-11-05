/************************************************************************
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
\
2
/
3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
************************************************************************/

//solution
//Recursive

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
	void get_res(TreeNode *root, vector<int> &V)
	{
		if (root != NULL)
		{
			V.push_back(root->val);
			get_res(root->left, V);
			get_res(root->right, V);
		}
	}
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> V;
		get_res(root, V);
		return V;
	}
};