/************************************************************************
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.


************************************************************************/

//solution
//ugly
class Solution {
public:
	bool isAlphaNum(char ch)
	{
		if ((ch >= '0' && ch <= '9') ||
			(ch >= 'a' && ch <= 'z') ||
			(ch >= 'A' && ch <= 'Z'))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool eq(char ch1, char ch2)
	{
		if (ch1 >= '0' && ch1 <= '9' && 
			ch2 >= '0' && ch2 <= '9')
		{
			if (ch1 == ch2)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		if (ch1 >= 'a' && ch1 <= 'z' &&
			((ch2 >= 'a' && ch2 <= 'z') || (ch2 >= 'A' && ch2 <= 'Z')))
		{
			if (ch2 >= 'a' && ch2 <= 'z')
			{
				if (ch1 == ch2)
				{
					return true;
				}
			}
			else
			{
				if (ch1 == (ch2-'A' + 'a'))
				{
					return true;
				}
			}
		}

		if (ch1 >= 'A' && ch1 <= 'Z' &&
			((ch2 >= 'a' && ch2 <= 'z') || (ch2 >= 'A' && ch2 <= 'Z')))
		{
			if (ch2 >= 'a' && ch2 <= 'z')
			{
				if (ch1 == (ch2-'a' + 'A'))
				{
					return true;
				}
			}
			else
			{
				if (ch1 == ch2)
				{
					return true;
				}
			}
		}

		return false;
	}
	bool isPalindrome(string s) {
		if (s.empty())
		{
			return true;
		}
		int st = 0;
		int en = s.length() - 1;
		//bool flag = false;
		while(st < en)
		{
			while(!isAlphaNum(s[st]) && st < en)
			{
				st ++;
			}
			while(!isAlphaNum(s[en]) && st < en)
			{
				en --;
			}
			if (st >= en)
				break;
			if (!eq(s[st], s[en]))
			{
				return false;
			}
			else
			{
				st ++;
				en --;
				//flag = true;
			}
		}
		return true;
	}
};