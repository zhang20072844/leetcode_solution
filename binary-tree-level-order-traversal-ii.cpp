/************************************************************************
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
************************************************************************/


#include <iostream>
#include <string>
using namespace std;

//alittle ugly
struct QueueNode
{
	int level;
	TreeNode *next;
};
class Solution {
public:
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > res;
		stack<vector<int> >st;
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
				st.push(oneLevel);
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
			st.push(oneLevel);
		while(!st.empty())
		{
			res.push_back(st.top());
			st.pop();
		}
		return res;
	}
};

int main()
{

	ListNode *a = new ListNode(2);
	ListNode *b = NULL;
	Solution solution;
	solution.getIntersectionNode(a,b);
	return 0;
}