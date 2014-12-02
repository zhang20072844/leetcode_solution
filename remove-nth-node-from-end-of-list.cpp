/************************************************************************
Given a linked list, remove the nth node from the end of list and return its head.

For example,

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

Show Tags Linked List Two Pointers

************************************************************************/


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
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode *pre = head;
		ListNode *cur = head->next;
		ListNode *end = head;
		int num = n;
		while(num && end)
		{
			end = end->next;
			num --;
		}

		if (NULL == end)
		{
			return head->next;
		}

		end = end->next;
		while(end != NULL)
		{
			pre = pre->next;
			cur = cur->next;
			end = end->next;
		}

		pre->next = cur->next;
		delete cur;

		return head;
	}
};

//add new head node good

class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		// return if NULL
		if (head == NULL)
			return NULL;
		// define a dummy head, dummyHead->next = head;
		ListNode dummyHead(0); dummyHead.next = head;
		ListNode *fast = &dummyHead, *slow = &dummyHead;
		// let fast_pointer be n nodes ahead than slow_pointer
		while (n--) {
			fast = fast->next; 
		} 
		// move fast_pointer and slow_pointer in the same pace
		while (fast != NULL && fast->next != NULL) { 
			fast = fast->next;
			slow = slow->next;
		}
		// delete slow->next
		slow->next = slow->next->next;
		// return the actual head
		return dummyHead.next;
	}
};
int main()
{

	ListNode *a = new ListNode(2);
	ListNode *b = NULL;
	Solution solution;
	solution.getIntersectionNode(a,b);
	return 0;
}