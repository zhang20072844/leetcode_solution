/************************************************************************
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
************************************************************************/

//solution
//

class Solution {
public:
	bool isPalindrome(int x) {
		if(x<0)
			return false;
		if(x<10)
			return true;
		int half = x;
		int len = 0;
		int i = 0;
		while(half)
		{
			half /= 10;
			len ++;
		}
		half=0;
		while(x)
		{
			half = half*10 + (x%10);
			x/=10;
			i ++;
			if (i == len/2)
			{
				if (((len&1) &&(half*10+(x%10) == x)) ||
					(!(len&1) && half == x))
					return true;
			}
			if (i > len/2)
				break;
		}


		return false;
	}
};