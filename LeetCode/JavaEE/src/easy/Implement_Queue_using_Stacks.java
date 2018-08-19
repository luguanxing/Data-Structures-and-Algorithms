package easy;

import java.util.Stack;

public class Implement_Queue_using_Stacks {

	class MyQueue {
		Stack<Integer> s1 = new Stack<>();
		Stack<Integer> s2 = new Stack<>();

		public MyQueue() {

		}

		public void push(int x) {
			s1.add(x);
		}

		public int pop() {
			if (!s2.isEmpty()) {
				return s2.pop();
			} else {
				while (!s1.isEmpty()) {
					s2.push(s1.pop());
				}
				return s2.pop();
			}
		}

		public int peek() {
			if (s2.isEmpty()) {
				while (!s1.isEmpty()) {
					s2.push(s1.pop());
				}
			}
			return s2.peek();
		}

		public boolean empty() {
			return s1.isEmpty() && s2.isEmpty();
		}
	}

	public static void main(String[] args) {
		Implement_Queue_using_Stacks main = new Implement_Queue_using_Stacks();
		MyQueue queue = main.new MyQueue();
		queue.push(1);
		queue.push(2);
		queue.push(3);
		System.out.println(queue.pop());
		System.out.println(queue.peek());
		System.out.println(queue.pop());
		System.out.println(queue.peek());
		System.out.println(queue.pop());
		System.out.println(queue.empty());
	}

}
