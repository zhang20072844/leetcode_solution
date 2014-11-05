/************************************************************************
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
************************************************************************/

//solution
//Recursive

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
	bool hasCycle(ListNode *head) {
		ListNode *p = head;
		ListNode *q = head;

		while(p != NULL && q != NULL)
		{
			p = p->next;
			q = q->next;
			if (q != NULL)
			{
				q = q->next;
			}
			else
			{
				return false;
			}

			if (p == q)
			{
				return true;
			}
		}
		return false;
	}
};