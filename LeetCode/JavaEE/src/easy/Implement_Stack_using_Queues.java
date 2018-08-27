package easy;

import java.util.LinkedList;
import java.util.Queue;

public class Implement_Stack_using_Queues {

	class MyStack {

		Queue<Integer> q1 = new LinkedList<>();

		Queue<Integer> q2 = new LinkedList<>();

		public MyStack() {

		}

		public void push(int x) {
			q1.add(x);
		}

		public int pop() {
			// q1作为顺序存储，q2作为中转站，pop时将q1除最后一个外存入q2中，取出最后一个返回，再将中转站元素存回q1
			while (!q1.isEmpty()) {
				if (q1.size() == 1) {
					Integer ret = q1.poll();
					while (!q2.isEmpty()) {
						q1.add(q2.poll());
					}
					return ret;
				}
				q2.add(q1.poll());
			}
			return -1;
		}

		public int top() {
			// 先pop再存回p1，总体顺序不变
			int ret = pop();
			q1.add(ret);
			return ret;
		}

		public boolean empty() {
			return q1.isEmpty() && q2.isEmpty();
		}
	}

	public static void main(String[] args) {
		Implement_Stack_using_Queues main = new Implement_Stack_using_Queues();
		MyStack stack = main.new MyStack();
		stack.push(1);
		stack.push(2);
		System.out.println(stack.top());
		System.out.println(stack.pop());
		System.out.println(stack.empty());
	}

}
