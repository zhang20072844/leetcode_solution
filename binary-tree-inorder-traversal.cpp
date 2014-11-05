/************************************************************************
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
\
2
/
3
return [1,3,2].

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
			get_res(root->left, V);
			V.push_back(root->val);
			get_res(root->right, V);
		}
	}
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> V;
		get_res(root, V);
		return V;
	}
};