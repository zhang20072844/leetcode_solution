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

class Solution {
public:
	string convert(string s, int nRows) {
		if (s == "" || nRows == 1)
		{
			return s;
		}
		vector<vector<char> >res;
		//res.reserve(nRows);
		bool flag = false;
		vector<char>tmp0;
		tmp0.push_back(s[0]);
		res.push_back(tmp0);
		for (int i = 1; i < s.length(); ++ i)
		{
			for (int j = 1; j < nRows && i < s.length(); ++ j)
			{
				if (!flag)
				{
					vector<char>tmp;
					tmp.push_back(s[i++]);
					res.push_back(tmp);
				}
				else
					res[j].push_back(s[i++]);
			}
			flag = true;
			for (int k = nRows - 2; k >= 0 &&  i < s.length(); -- k)
			{
				res[k].push_back(s[i++]);
			}
			i --;
		}

		string ans;
		for(int i = 0; i < res.size(); ++ i)
		{
			for (int j = 0; j < res[i].size(); ++ j)
			{
				ans += res[i][j];
			}
		}
		return ans;
	}
};

//great
public String convert(String s, int nRows) {
	char[] c = s.toCharArray();
	int len = c.length;
	StringBuffer[] sb = new StringBuffer[nRows];
	for (int i = 0; i < sb.length; i++) sb[i] = new StringBuffer();

	int i = 0;
	while (i < len) {
		for (int idx = 0; idx < nRows && i < len; idx++) // vertically down
			sb[idx].append(c[i++]);
		for (int idx = nRows-2; idx >= 1 && i < len; idx--) // obliquely up
			sb[idx].append(c[i++]);
	}
	for (int idx = 1; idx < sb.length; idx++)
		sb[0].append(sb[idx]);
	return sb[0].toString();
}
int main()
{

	ListNode *a = new ListNode(2);
	ListNode *b = NULL;
	Solution solution;
	solution.getIntersectionNode(a,b);
	return 0;
}