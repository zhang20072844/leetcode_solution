/************************************************************************
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
5
/ \
4   8
/   / \
11  13  4
/  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

************************************************************************/

//solution
//
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
	bool hasPathSum(TreeNode *root, int sum) {
		if (sum <= 0)
			return false;
		if (root == NULL)
			return false;
		if (root != NULL && root->left==NULL && root->right==NULL && sum == root->val)
		{
			return true;
		}

		sum -= root->val;
		if (root->left != NULL)
		{
			return hasPathSum(root->left, sum);
		}

		if (root->right != NULL)
		{
			return hasPathSum(root->right, sum);
		}
		sum += root->val;

	}
};