/************************************************************************
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
************************************************************************/

/*
One simple approach is a two-pass solution: First pass to split the string by spaces into an array of words, then second pass to extract the words in reversed order.

We can do better in one-pass. While iterating the string in reverse order, we keep track of a word¡¯s begin and end position. When we are at the beginning of a word, we append it.

Cancel rating12345
Average Rating: 4.2 (87 votes)

Is this solution helpful? Read our book to learn more.
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	void reverseAword(string &s)
	{

	}
	void reverseWords(string &s) {
		int i = 0;
		stack<string>words;
		string str("");
		while (i < s.length())
		{
			str.clear();
			while (s[i] == ' ' && i < s.length())
			{
				i ++;
			}
			while (s[i] != ' ' && i < s.length())
			{
				str += s[i];
				i ++;
			}
			if (i < s.length())
				words.push(str);
		}
		if(!str.empty())
		{
			words.push(str);
		}
		s.clear();
		if (!words.empty())
		{
			s += words.top();
			words.pop();
		}
		while(!words.empty())
		{
			s += " " + words.top();
			words.pop();
		}
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