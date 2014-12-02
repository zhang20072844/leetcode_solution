/************************************************************************
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
************************************************************************/

/*
O(n2) runtime, O(1) space ¨C Brute force:

The brute force approach is simple. Loop through each element x and find if there is another value that equals to target ¨C x. As finding another value requires looping through the rest of array, its runtime complexity is O(n2).

O(n) runtime, O(n) space ¨C Hash table:

We could reduce the runtime complexity of looking up a value to O(1) using a hash map that maps a value to its index.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//my solution
#include <algorithm>
class Solution {
public:
	struct Elem
	{
		int index;
		int num;
		bool operator<(const struct Elem &other)
		{
			return num < other.num;
		}
	};
	bool cmp(const struct Elem &a, const struct Elem &b)
	{
		return a.num < b.num;
	}
	bool binary_search(vector<Elem>&nums, int l, int r, int tar, int &index)
	{
		int low = l;
		int high = r;
		while(low <= high)
		{
			int mid = low + (high-low)/2;
			if (nums[mid].num == tar)
			{
				index = mid;
				return true;
			}
			else if (nums[mid].num < tar)
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
		return false;
	}
	vector<int> twoSums(vector<int> &numbers, int target) {
		vector<Elem>nums;
		nums.reserve(numbers.size());
		for (int i = 0; i < numbers.size(); ++ i)
		{
			Elem elem;
			elem.index = i + 1;
			elem.num = numbers[i];
			nums.push_back(elem);
		}

		//std::sort(nums.begin(), nums.end());
		vector<int>res;
		for (int i = 0; i < nums.size() - 1; ++ i)
		{
			int tarIndex;
			if(binary_search(nums, i + 1, nums.size()-1, target - nums[i].num, tarIndex))
			{

				if (nums[i].index < nums[tarIndex].index)
				{
					res.push_back(nums[i].index);
					res.push_back(nums[tarIndex].index);
				}
				else
				{
					res.push_back(nums[tarIndex].index);
					res.push_back(nums[i].index);
				}
				break;
			}
		}

		return res;
	}

	//great o(n)time o(n)space
	vector<int> twoSum(vector<int> &numbers, int target) {
		unordered_map<int, int>num;
		for(int i = 0; i < numbers.size(); ++ i)
		{
			//num[numbers[i]] = i+1;
			int tmp = target - numbers[i];
			if (num.find(tmp) != num.end())
			{
				vector<int>res;
				res.push_back(num[tmp]);
				res.push_back(i+1);
				return res;
			}
			num[numbers[i]] = i + 1;
		}
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