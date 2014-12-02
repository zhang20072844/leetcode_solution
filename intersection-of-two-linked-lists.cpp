/************************************************************************
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 ¡ú a2
¨K
c1 ¡ú c2 ¡ú c3
¨J            
B:     b1 ¡ú b2 ¡ú b3
begin to intersect at node c1.
************************************************************************/


/*

There are many solutions to this problem:

Brute-force solution (O(mn) running time, O(1) memory):
For each node ai in list A, traverse the entire list B and check if any node in list B coincides with ai.

Hashset solution (O(n+m) running time, O(n) or O(m) memory):
Traverse list A and store the address / reference to each node in a hash set. Then check every node bi in list B: if bi appears in the hash set, then bi is the intersection node.

Two pointer solution (O(n+m) running time, O(1) memory):
Maintain two pointers pA and pB initialized at the head of A and B, respectively. Then let them both traverse through the lists, one node at a time.
When pA reaches the end of a list, then redirect it to the head of B (yes, B, that's right.); similarly when pB reaches the end of a list, redirect it the head of A.
If at any point pA meets pB, then pA/pB is the intersection node.
To see why the above trick would work, consider the following two lists: A = {1,3,5,7,9,11} and B = {2,4,9,11}, which are intersected at node '9'. Since B.length (=4) < A.length (=6), pB would reach the end of the merged list first, because pB traverses exactly 2 nodes less than pA does. By redirecting pB to head A, and pA to head B, we now ask pB to travel exactly 2 more nodes than pA would. So in the second iteration, they are guaranteed to reach the intersection node at the same time.
If two lists have intersection, then their last nodes must be the same one. So when pA/pB reaches the end of a list, record the last element of A/B respectively. If the two last elements are not the same one, then the two lists have no intersections.

*/


#include <iostream>
#include <string>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	int getListLen(ListNode * head)
	{
		int len = 0;
		while (head != NULL)
		{
			len ++;
			head = head->next;
		}
	}
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *a = headA;
		ListNode *b = headB;
		int lenA = getListLen(a);
		int lenB = getListLen(b);

		while(lenA > lenB)
		{
			a = a->next;
			lenA --;
		}

		while (lenB > lenA)
		{
			b = b->next;
			lenB --;
		}

		while (a != b)
		{

			a = a->next;
			b = b->next;
		}

		return NULL;
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