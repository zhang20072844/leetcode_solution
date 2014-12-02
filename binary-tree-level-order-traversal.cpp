/************************************************************************
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
3
/ \
9  20
/  \
15   7
return its level order traversal as:
[
[3],
[9,20],
[15,7]
]
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
struct QueueNode
{
	int level;
	TreeNode *next;
};
class Solution {
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > res;
		queue<QueueNode>Q;
		if (root != NULL)
		{
			QueueNode qnode;
			qnode.level = 0;
			qnode.next = root;
			Q.push(qnode);
		}
		vector<int>oneLevel;
		int cur_level = 0;
		while(!Q.empty())
		{
			QueueNode &qnode = Q.front();
			if (qnode.level == cur_level)
			{
				oneLevel.push_back((qnode.next)->val);
			}
			else
			{
				res.push_back(oneLevel);
				oneLevel.clear();
				oneLevel.push_back((qnode.next)->val);
				cur_level ++;
			}
			Q.pop();
			if ((qnode.next)->left != NULL)
			{
				QueueNode tmp;
				tmp.level = cur_level +1;
				tmp.next = (qnode.next)->left;
				Q.push(tmp);
			}
			if ((qnode.next)->right != NULL)
			{
				QueueNode tmp;
				tmp.level = cur_level +1;
				tmp.next = (qnode.next)->right;
				Q.push(tmp);
			}
		}
		if (!oneLevel.empty())
			res.push_back(oneLevel);

		return res;
	}
};
int main()
{

	int n = 7;
	MinStack solution;
	solution.push(-3);
	cout << solution.getMin()<<endl;
	return 0;
}