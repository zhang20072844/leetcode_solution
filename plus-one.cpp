/************************************************************************
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
************************************************************************/

//solution
//n g

class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		vector<int> res;
		if (digits.empty())
		{
			return res;
		}

		res.reserve(digits.size()+1);
		int flag = 1;
		for (int i = digits.size() - 1; i >= 0; -- i)
		{
			//digits[i] = digits[i] + flag
			if (digits[i] + flag >= 10)
			{
				digits[i] = (digits[i] + flag) % 10;
				flag = 1;
			}
			else
			{
				digits[i] = digits[i] + flag;
				flag = 0;
			}
		}

		if (flag > 0)
		{
			res.push_back(flag);
			res.insert(res.end(), digits.begin(), digits.end());
		}
		else
		{
			res.assign(digits.begin(), digits.end());
		}

		return res;
	}
};