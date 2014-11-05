/************************************************************************
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
************************************************************************/

//solution
//

class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		// int len = 0;
		int cur = 0;
		for (int i = 0; i < n; ++ i)
		{
			if (A[i] == elem)
			{
				continue;
			}
			else
			{
				A[cur++] = A[i]; 
			}
		}
		return cur;
	}
};