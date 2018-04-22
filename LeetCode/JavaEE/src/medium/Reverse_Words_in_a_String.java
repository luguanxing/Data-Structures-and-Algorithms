package medium;

public class Reverse_Words_in_a_String {

	public class Solution {
		public String reverseWords(String s) {
			String[] strs = s.trim().split(" ");
			StringBuilder sb = new StringBuilder();
			for (int i = strs.length - 1; i >= 0; i--) {
				if (strs[i].isEmpty() || strs[i].equals(" ")) {
					continue;
				}
				sb.append(strs[i]);
				if (i != 0) {
					sb.append(" ");
				}
			}
			return sb.toString();
		}
	}

	public static void main(String[] args) {
		String s = "  1";
		System.out.println(new Reverse_Words_in_a_String().new Solution().reverseWords(s));
	}

}
