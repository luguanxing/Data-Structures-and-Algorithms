package easy;

public class Backspace_String_Compare {

	class Solution {
		public boolean backspaceCompare(String S, String T) {
			StringBuilder sb1 = new StringBuilder();
			for (int i = 0; i < S.length(); i++) {
				if (S.charAt(i) == '#') {
					if (sb1.length() > 0) {
						sb1.deleteCharAt(sb1.length() - 1);
					}
				} else {
					sb1.append(S.charAt(i));
				}
			}
			StringBuilder sb2 = new StringBuilder();
			for (int i = 0; i < T.length(); i++) {
				if (T.charAt(i) == '#') {
					if (sb2.length() > 0) {
						sb2.deleteCharAt(sb2.length() - 1);
					}
				} else {
					sb2.append(T.charAt(i));
				}
			}
			return sb1.toString().equals(sb2.toString());
		}
	}

	public static void main(String[] args) {
		String S = "xywrrmp";
		String T = "xywrrmu#p";
		System.out.println(new Backspace_String_Compare().new Solution().backspaceCompare(S, T));
	}
}
