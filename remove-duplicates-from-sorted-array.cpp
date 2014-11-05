/************************************************************************
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
************************************************************************/

//solution
//easy

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (0 == n)
		{
			return n;
		}
		int cur = 0;
		int i = 1;
		while(i < n)
		{
			if (A[i] == A[cur])
			{
				i ++;
			}
			else
			{
				A[cur+1] = A[i];
				cur ++;
				i ++;
			}
		}
		return cur+1;
	}
};