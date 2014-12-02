/************************************************************************
Implement pow(x, n).

Hide Tags Math Binary Search

************************************************************************/


#include <iostream>
#include <string>
using namespace std;
//my solution
class Solution {
public:
	double pow(double x, int n) {
		double ans = 1.0;
		double tmp = x;
		bool flag = false;
		long long nt = n;
		if (n < 0)
		{
			flag = true;
			nt = (long long)0 -n;
		}
		while(nt)
		{
			if (nt&1)
				ans *= tmp;
			tmp *= tmp;
			nt >>= 1;
		}

		return flag ? 1/ans : ans;
	}
};

//good
public class Solution {
	public double pow(double x, int m) {
		double temp=x;
		if(m==0)
			return 1;
		temp=pow(x,m/2);
		if(m%2==0)
			return temp*temp;
		else 
		{
			if(m > 0)
				return x*temp*temp;
			else
				return (temp*temp)/x;
		}

	}
int main()
{

	ListNode *a = new ListNode(2);
	ListNode *b = NULL;
	Solution solution;
	solution.getIntersectionNode(a,b);
	return 0;
}