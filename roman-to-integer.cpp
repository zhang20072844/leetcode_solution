/************************************************************************
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.


************************************************************************/

//solution
//wiki
class Solution {
public:
	int romanToInt(string s) {
		int res = 0;
		int now = 0;
		int old = 0;
		for (int i = 0; i < s.length(); ++ i)
		{

			switch(s[i])
			{
			case 'M':
				now = 1000;
				break;
			case 'D':
				now = 500;
				break;
			case 'C':
				now = 100;
				break;
			case 'L':
				now = 50;
				break;
			case 'X':
				now = 10;
				break;
			case 'V':
				now = 5;
				break;
			case 'I':
				now = 1;
				break;
			}
			if (now > old)
			{
				res += now;
				res -= 2*old;
			}
			else 
			{
				res += now;
			}
			old = now;
		}
		return res;
	}
};