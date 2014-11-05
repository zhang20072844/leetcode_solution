/************************************************************************
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.************************************************************************/

//solution
//consider the head zeros

class Solution {
public:
	int atoi(const char *str) {
		int sum = 0;
		int sign = 0;
		if (str == NULL)
		{
			return sum;
		}
		while(*str == ' ' && *str != '\0')
		{
			str ++;
		}

		if (*str == '-')
		{
			sign = 1;
			str ++;
		}
		else if (*str == '+')
		{
			sign = 0;
			str ++;
		}

		while(*str == '0' && *str != '\0')
		{
			str ++;
		}

		while(*str != '\0')
		{
			if (*str >= '0' && *str <= '9')
			{
				//sum = sum * 10 + (*str - '0');
				if (sign)
				{
					if (-sum < (-2147483648 + (*str - '0'))/10)
					{
						return -2147483648;
					}
					else
					{
						sum = sum * 10 + (*str - '0');
					}
				}
				else
				{
					if (sum > (2147483647 - (*str - '0'))/10)
					{
						return 2147483647;
					}
					else
					{
						sum = sum * 10 + (*str - '0');
					}
				}
			}
			else
			{
				break;
			}
			str ++;
		}

		return sign ? -sum : sum;
	}
};