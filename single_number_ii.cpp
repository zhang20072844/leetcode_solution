/************************************************************************
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
************************************************************************/

/*
public int singleNumber(int[] A) {
int ones = 0, twos = 0;
for(int i = 0; i < A.length; i++){
ones = (ones ^ A[i]) & ~twos;
twos = (twos ^ A[i]) & ~ones;
}
return ones;
}
asked Jun 25 in Single Number II by againest1 (220 points)

Show 11 previous comments
Sorry, didnt quite get what you meant by "the number appear n times", can you explain?

commented Nov 16 by pablocael

Every number appears 3 times except the one.

Suppose the one appear n times,

if n mod 3 == 1; then return first

if n mod 3 == 2; then return second

Got it ?

commented Nov 16 by krizex

Got it what you mean ;] Because if c = n mod 3, then 0 <= c< 3, But, in the algorithm posted, they are returning only ones, it may happen to fail, isnt it?

commented Nov 16 by pablocael

The algo posted is correct. Because the problem just want to find the number which appear 1 time, so return ones.

commented Nov 16 by krizex

Oh, thankz, I thought for some reason that one single distict number appears not three times but more thant 1. If irs only one then the algo is perfect. Thanks.

commented Nov 17 by pablocael

7 Answers


+33
votes
The code seems tricky and hard to understand at first glance. However, if you consider the problem in Boolean algebra form, everything becomes clear.

What we need to do is to store the number of '1's of every bit. Since each of the 32 bits follow the same rules, we just need to consider 1 bit. We know a number appears 3 times at most, so we need 2 bits to store that. Now we have 4 state, 00, 01, 10 and 11, but we only need 3 of them.

In this solution, 00, 01 and 10 are chosen. Let 'ones' represents the first bit, 'twos' represents the second bit. Then we need to set rules for 'ones' and 'twos' so that they act as we hopes. The complete loop is 00->10->01->00(0->1->2->3/0).

For 'ones', we can get 'ones = ones ^ A[i]; if (twos == 1) then ones = 0', that can be tansformed to 'ones = (ones ^ A[i]) & ~twos'.

Similarly, for 'twos', we can get 'twos = twos ^ A[i]; if (ones* == 1) then twos = 0' and 'twos = (twos ^ A[i]) & ~ones'. Notice that 'ones*' is the value of 'ones' after calculation, that is why twos is calculated later.

Here is another example. If a number appears 5 times at most, we can write a program using the same method. Now we need 3 bits and the loop is 000->100->010->110->001. The code looks like this:

int singleNumber(int A[], int n) {
int na = 0, nb = 0, nc = 0;
for(int i = 0; i < n; i++){
nb = nb ^ (A[i] & na);
na = (na ^ A[i]) & ~nc;
nc = nc ^ (A[i] & ~na & ~nb);
}
return na & ~nb & ~nc;
}
Or even like this:

int singleNumber(int A[], int n) {
int twos = 0xffffffff, threes = 0xffffffff, ones = 0;
for(int i = 0; i < n; i++){
threes = threes ^ (A[i] & twos);
twos = (twos ^ A[i]) & ~ones;
ones = ones ^ (A[i] & ~twos & ~threes);
}
return ones;
}
I hope all these above can help you have a better understand of this problem.

answered Oct 18 by woshidaishu (390 points) 
edited Oct 18 by woshidaishu

beautiful explanation! I just feel the whole world is good again.

commented Oct 24 by D.W.

This just explained the algorithm. Otherwise the implementation by finite-state machine is hard to understand.

commented Oct 30 by peteraristo

This is very elegant. Thanks!

commented Nov 18 by minyaozhu

Thank you for your clear explanation.

commented Nov 21 by wenzhiquan

so beautiful

commented 2 days ago by sonald


*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//my solution
class Solution {
public:
	int singleNumber(int A[], int n) {
		vector<int>times;
		times.resize(32,0);

		for (int i = 0; i < n; ++ i)
		{
			int num = A[i] ;//< 0? -A[i]:A[i];
			int j = 0;
			while(j < 32)
			{
				times[j] += num & 1;
				j ++;
				num >>= 1;
			}
		}
		int res = 0;
		for (int i = 0; i < times.size(); ++ i)
		{
			res |= ((times[i]%3) << i);
		}

		return res;
	}
};
int main()
{

	Solution solution;
	vector<int>res;
	vector<int >nums;
	nums.push_back(7);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	res = solution.twoSum(nums, 9);
	
	return 0;
}