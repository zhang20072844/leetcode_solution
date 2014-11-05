/************************************************************************
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]

************************************************************************/

//solution
//
class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> >res;
		if (0 == numRows)
		{
			return res;
		}
		vector<int>row;
		row.push_back(1);
		res.push_back(row);
		for (int i = 1; i < numRows; ++ i)
		{
			row.clear();
			row.resize(i+1);
			row[0] = 1;
			row[i] = 1;
			if (i >= 2)
			{
				for(int j = 1; j < i; ++ j)
				{
					row[j] = res[i-1][j-1] + res[i-1][j];
				}
			}
			res.push_back(row);
		}
		return res;
	}
};