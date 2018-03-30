package medium;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

public class Generate_Parentheses {

	class Solution {
		
		Set<String> set = new TreeSet<>();

		List<String> result = new ArrayList<>();

		public void makeIt(int leftNum, String str) {
			if (leftNum == 0) {
				set.add(new String(str));
				return;
			}
			for (int i = 0; i < str.length(); i++) {
				makeIt(leftNum - 1, str.substring(0, i) + "()" + str.substring(i));
			}
		}

		public List<String> generateParenthesis(int n) {
			makeIt(n - 1, "()");
			result.addAll(set);
			return result;
		}

	}

	public static void main(String[] args) {
		System.out.println(new Generate_Parentheses().new Solution().generateParenthesis(3));
	}

}
