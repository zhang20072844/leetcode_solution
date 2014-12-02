/************************************************************************
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
************************************************************************/


/*

Hints:
Consider space-time tradeoff. How would you keep track of the minimums using extra space?
Make sure to consider duplicate elements.
O(n) runtime, O(n) space ¨C Extra stack:

Use an extra stack to keep track of the current minimum value. During the push operation we choose the new element or the current minimum, whichever that is smaller to push onto the min stack.

O(n) runtime, O(n) space ¨C Minor space optimization:

If a new element is larger than the current minimum, we do not need to push it on to the min stack. When we perform the pop operation, check if the popped element is the same as the current minimum. If it is, pop it off the min stack too.
*/


#include <iostream>
#include <string>
using namespace std;

class MinStack {
public:
	void push(int x) {
		if(st.empty())
		{
			st.push(x);
			min.push(x);
		}
		else
		{
			if (x <= min.top())
			{
				min.push(x);
			}
			st.push(x);
		}
	}

	void pop() {
		if (st.top() == min.top())
		{
			min.pop();
		}
		st.pop();

	}

	int top() {
		return st.top();
	}

	int getMin() {
		return min.top();
	}
private:
	stack<int>st;
	stack<int>min;
};

//great
public class MinStack {
	long min;
	Stack<Long> stack;

	public MinStack(){
		stack=new Stack<>();
	}

	public void push(int x) {
		if (stack.isEmpty()){
			stack.push(0L);
			min=x;
		}else{
			stack.push(x-min);//Could be negative if min value needs to change
			if (x<min) min=x;
		}
	}

	public void pop() {
		if (stack.isEmpty()) return;

		long pop=stack.pop();

		if (pop<0)  min=min-pop;//If negative, increase the min value

	}

	public int top() {
		long top=stack.peek();
		if (top>0){
			return (int)(top+min);
		}else{
			return (int)(min);
		}
	}

	public int getMin() {
		return (int)min;
	}
}




int main()
{

	ListNode *a = new ListNode(2);
	ListNode *b = NULL;
	Solution solution;
	solution.getIntersectionNode(a,b);
	return 0;
}