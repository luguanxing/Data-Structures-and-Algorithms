package easy;

import java.util.Stack;

public class Min_Stack {

	class MinStack {

		// 原始数据栈
		Stack<Integer> data = new Stack<>();
		// 最小辅助栈
		Stack<Integer> min = new Stack<>();

		public MinStack() {

		}

		public void push(int x) {
			data.push(x);
			// 若更小则放入，否则放入当前最小(即top)
			if (!min.isEmpty()) {
				Integer top = min.peek();
				if (top < x) {
					min.push(top);
				} else {
					min.push(x);
				}
			} else {
				min.push(x);
			}
		}

		public void pop() {
			data.pop();
			min.pop();
		}

		public int top() {
			return data.peek();
		}

		public int getMin() {
			return min.peek();
		}
	}

	public static void main(String[] args) {
		MinStack minStack = new Min_Stack().new MinStack();
		minStack.push(-2);
		minStack.push(0);
		minStack.push(-3);
		int res1 = minStack.getMin();
		minStack.pop();
		int res2 = minStack.top();
		int res3 = minStack.getMin();
		System.out.println(res1);
		System.out.println(res2);
		System.out.println(res3);
	}

}
