/************************************************************************
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.
************************************************************************/

//solution
//binary search

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int strStr(char *haystack, char *needle) {
		if (NULL == haystack || NULL == needle)
		{
			return -1;
		}
		
		for (int i = 0; haystack[i] != '\0'; ++ i)
		{
			char *p = haystack+i;
			char *q = needle;
			while (*p != '\0' && *q != '\0')
			{
				if (*p == *q)
				{
					continue;
				}
				else
				{
					break;
				}
				p++;
				q++;
			}
			if (*q == \0'')
			{
				return i;
			}
		}

		return -1;
	}
};

int main()
{

	int n = 7;
	Solution solution;
	cout << solution.lengthOfLastWord("hello world.     ")<<endl;
	return 0;
}