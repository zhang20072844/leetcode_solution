/************************************************************************
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
************************************************************************/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//my solution
class Solution {
public:
	void swaps(int *a, int *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
	void sortColors(int A[], int n) {
		int start = 0;
		int end = n -1;
		int i = 0;
		while(i <= end)
		{
			if (start >= end)
			{
				break;
			}
			if(A[i] == 2)
			{
				swaps(&A[i], &A[end]);
				end --;
			}
			if (A[i] == 0)
			{
				swaps(&A[i], &A[start]);
				start ++;
				i ++;
			}
			if (A[i] == 1)
			{
				i ++;
			}
		}
	}
};

//great
class Solution {
public:
	//use counting sort
	void sortColors(int A[], int n) {
		int red = -1, white = -1, blue = -1;

		for(int i = 0; i < n; i++){
			if(A[i] == 0){   
				A[++blue] = 2;
				A[++white] = 1;
				A[++red] = 0;
			}
			else if(A[i] == 1){
				A[++blue] = 2;
				A[++white] = 1;
			}
			else if(A[i] == 2)   
				A[++blue] = 2;
		}
	}
};
int main()
{

	Solution solution;
	int A[] = {1,1,2};
	solution.sortColors(A, 3);
	
	return 0;
}