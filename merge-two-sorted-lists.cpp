/************************************************************************
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
************************************************************************/

//ugly

#include <iostream>
#include <string>
using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (NULL == l1)
		{
			return l2;
		}

		if (NULL == l2)
		{
			return l1;
		}

		ListNode *res =NULL;
		ListNode *ans = NULL;
		ListNode *cur;
		while (l1 != NULL && l2 != NULL)
		{
			cur = new ListNode(0);


			if (l1->val < l2->val)
			{
				cur->val = l1->val;
				l1 = l1->next;
			}
			else
			{
				cur->val = l2->val;
				l2=l2->next;
			}

			if (NULL == res)
			{
				res = cur;
				ans = res;
			}
			else
			{
				res->next = cur;
				res = res->next;
			}

		}

		if (l1 != NULL)
		{
			res ->next = l1;
		}

		if (l2 != NULL)
		{
			res->next =l2;
		}
		return ans;
	}
};


//no other space
class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (NULL == l1)
		{
			return l2;
		}

		if (NULL == l2)
		{
			return l1;
		}

		ListNode *head =NULL;
		if (l1->val < l2->val)
		{
			head = l1;
			l1=l1->next;
		}
		else
		{
			head = l2;
			l2=l2->next;
		}

		ListNode *cur =head;
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				cur->next = l1;
				l1 = l1->next;
			}
			else
			{
				cur->next = l2;
				l2=l2->next;
			}
			cur = cur->next;
		}

		if (l1 != NULL)
		{
			cur ->next = l1;
		}

		if (l2 != NULL)
		{
			cur->next =l2;
		}
		return head;
	}
};
int main()
{

	int n = 7;
	MinStack solution;
	solution.push(-3);
	cout << solution.getMin()<<endl;
	return 0;
}