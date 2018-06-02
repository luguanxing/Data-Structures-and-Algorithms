package easy;

import java.util.Stack;

public class Valid_Parentheses {

	class Solution {
		public boolean isValid(String s) {
			if (s == null) {
				return false;
			}
			Stack<Character> stack = new Stack();
			for (int i = 0; i < s.length(); i++) {
				char val = s.charAt(i);
				if (val == '(' || val == '[' || val == '{') {
					stack.push(val);
				} else {
					if (stack.isEmpty()) {
						return false;
					}
					Character top = stack.peek();
					if (val == ')' && top == '(') {
						stack.pop();
						continue;
					}
					if (val == ']' && top == '[') {
						stack.pop();
						continue;
					}
					if (val == '}' && top == '{') {
						stack.pop();
						continue;
					}
					return false;
				}
			}
			return stack.isEmpty();
		}
	}

	public static void main(String[] args) {
		String s = "[";
		System.out.println(new Valid_Parentheses().new Solution().isValid(s));
	}
	
}
