/************************************************************************
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

************************************************************************/

//solution
//notice overflow longlong
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int>res;
		res.resize(rowIndex+1);
		res[0] = res[rowIndex] = 1;
		int len = (rowIndex+1)/2;
		long long k = 1;//rowIndex;
		for (int i = 1; i <= len; ++ i)
		{
			k = k*(rowIndex - i + 1)/i;
			res[i] = k;
		}
		for (int i = rowIndex - 1; i > len; -- i)
		{
			res[i] = res[rowIndex-i];
		}
		return res;
	} 
};