/************************************************************************
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

1
/ \
2   2
/ \ / \
3  4 4  3
But the following is not:
1
/ \
2   2
\   \
3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
************************************************************************/

//solution
//binary search

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
	bool isSymmetric(TreeNode *root) {

		if (NULL == root)
		{
			return true;
		}
		queue<TreeNode *>ql;
		queue<TreeNode *>qr;
		ql.push(root->left);
		qr.push(root->right);

		while(!ql.empty() && !qr.empty())
		{
			TreeNode *l = ql.front();
			ql.pop();
			TreeNode *r = qr.front();
			qr.pop();

			if (NULL == l && NULL == r)
			{
				continue;
			}

			if (NULL == l || NULL == r)
			{
				return false;
			}

			if (l->val != r->val)
			{
				return false;
			}

			ql.push(l->left);
			ql.push(l->right);
			qr.push(r->right);
			qr.push(r->left);
		}
	}
};

int main()
{

	int n = 7;
	Solution solution;
	cout << solution.strStr("abcdefg", "cdf")<<endl;
	return 0;
}