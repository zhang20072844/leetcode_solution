/************************************************************************
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

************************************************************************/


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isMatch(char a, char b)
	{
		if ((a == '(' && b == ')') ||
			(a == '{' && b == '}') ||
			(a == '[' && b == ']'))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isValid(string s) {
		stack<char>st;
		for (int i = 0; i < s.length(); ++ i)
		{
			switch(s[i])
			{
			case '(':
			case '{':
			case '[':
				st.push(s[i]);
				break;
			case ')':
			case '}':
			case ']':
				if(!st.empty() && isMatch(st.top(), s[i]))
				{
					st.pop();
				}
				else
				{
					return false;
				}
			}
		}
		if (st.empty())
			return true;
		else
			return false;
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