/************************************************************************
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
************************************************************************/

//ugly

#include <iostream>
#include <string>
using namespace std;
//ugly
class Solution {
public:
	string addBinary(string a, string b) {
		int flag = 0;
		int len_a= a.length() -1;
		int len_b= b.length() -1;
		string res;
		while(len_a>=0 && len_b>=0)
		{
			int num = ((a[len_a] - '0') + (b[len_b]-'0') + flag);
			if (num >= 2)
			{
				flag = 1;
				num = num % 2;
			}
			else
				flag=0;
			if (num == 1)
			{
				res += "1";
			}
			else
			{
				res += "0";
			}
			len_a --;
			len_b--;
		}
		while(len_a>=0)
		{
			int num = ((a[len_a] - '0') + flag);
			if (num >= 2)
			{
				flag = 1;
				num = num % 2;
			}
			else
				flag=0;
			if (num)
			{
				res += "1";
			}
			else
			{
				res += "0";
			}
			len_a --;
		}
		while(len_b>=0)
		{
			int num = ((b[len_b]-'0') + flag);
			if (num >= 2)
			{
				flag = 1;
				num = num % 2;
			}
			else
				flag=0;
			if (num)
			{
				res += "1";
			}
			else
			{
				res += "0";
			}
			len_b --;
		}
		if (flag)
		{
			res += "1";
		}

		reverse(res.begin(), res.end());
		return res;
	}
};


//great
string addBinary(string a, string b) 
{
	string result = "";
	int apos = a.size() - 1;
	int bpos = b.size() - 1;
	int adigit, bdigit, carry = 0;

	while (apos >= 0 || bpos >= 0 || carry == 1)
	{
		adigit = bdigit = 0;

		if (apos >= 0) adigit = a[apos--] == '1';
		if (bpos >= 0) bdigit = b[bpos--] == '1';

		// Another way: the digit is 1 if adigit + bdigit + carry == 1 or == 3, but I noticed that
		// XOR is more concise:
		result = static_cast<char>(adigit ^ bdigit ^ carry + '0') + result; 
		carry = adigit + bdigit + carry >= 2;
	}

	return result;
}

int main()
{

	int n = 7;
	MinStack solution;
	solution.push(-3);
	cout << solution.getMin()<<endl;
	return 0;
}