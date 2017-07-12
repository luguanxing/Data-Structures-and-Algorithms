import java.util.Stack;

public class Solution {
	public static void main(String[] args) {
		Solution so = new Solution();
		System.out.println(so.isValid("([)]"));
	}
	
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
        	Character c = s.charAt(i);
			if (c == '(' || c == '[' || c == '{')
				st.push(c);
			else {
				switch (c) {
				case ')':
					if (st.peek() == '(')
						st.pop();
					else
						return false;
					break;
				case ']':
					if (st.peek() == '[')
						st.pop();
					else
						return false;
					break;
				case '}':
					if (st.peek() == '{')
						st.pop();
					else
						return false;
					break;
				default:
					break;
				}
			}
		}
        if (st.size() > 0)
        	return false;
    	return true;
    }
}
