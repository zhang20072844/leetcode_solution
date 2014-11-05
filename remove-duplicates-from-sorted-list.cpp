/************************************************************************
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
************************************************************************/

//solution
//easy

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
	ListNode *deleteDuplicates(ListNode *head) {
		ListNode *res = head;
		ListNode *p = head;
		ListNode *q = head;
		while(p != NULL)
		{
			q = p->next;
			while (q != NULL && p->val == q->val)
			{
				p->next = q->next;
				q = q->next;
			}
			p = p->next;
		}

		return res;
	}
};