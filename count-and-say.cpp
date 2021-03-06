/************************************************************************
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
************************************************************************/

//solution
//
class Solution {
public:

	static string countAndSay(int n) {
		string res("");
		if (0 == n)
		{
			return res;
		}
		res = "1";
		for (int i = 2; i <= n; ++ i)
		{
			string tmp = res;
			res = "";
			int num = 1;
			for (int j = 1; j < tmp.length(); ++ j)
			{
				if (tmp[j] == tmp[j-1])
				{
					num ++;
					continue;
				}
				else
				{
					char buf[100];
					sprintf(buf, "%d", num);
					res += buf;
					res += tmp[j-1];
					num = 1;
				}
			}
			char buf[100]={0};
			sprintf(buf, "%d", num);
			res += buf;
			res += tmp[tmp.length()-1];
		}
		return res;
	}
};
