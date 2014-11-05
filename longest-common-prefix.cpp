/************************************************************************
Write a function to find the longest common prefix string amongst an array of strings.

************************************************************************/

//solution
//not bad
class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {

		string res("");
		if (strs.empty())
		{
			return res;
		}
		res = strs[0];
		for (int i = 1; i < strs.size(); ++ i)
		{
			int j = 0;
			while(j < res.length() && j < strs[i].length())
			{
				if (res[j] != strs[i][j])
				{
					res = res.substr(0, j);
					break;
				}

				j ++;
			}
			if (j == strs[i].length())
			{
				res = res.substr(0, j);
			}
		}

		return res;
	}
};