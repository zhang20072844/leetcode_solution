/************************************************************************
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [?2,1,?3,4,?1,2,1,?5,4],
the contiguous subarray [4,?1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
************************************************************************/

//solution
//
class Solution {
public:
	int maxSubArray(int A[], int n) {
		int sum = 0;
		int res = -0x7FFFFFFF;
		for (int i = 0; i < n; ++ i)
		{
			if (A[i] > res)
			{
				res = A[i];
			}
		}
		if (res < 0)
		{
			return res;
		}
		res = -0x7FFFFFFF;
		sum = 0;
		for (int i = 0; i < n; ++ i)
		{
			if (sum < 0)
			{
				sum = A[i];
			}
			else
			{
				sum += A[i];
			}
			if (sum > res)
			{
				res = sum;
			}
		}
		return res;
	}
};