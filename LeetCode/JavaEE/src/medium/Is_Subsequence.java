package medium;

public class Is_Subsequence {

	class Solution {
		public boolean isSubsequence(String s, String t) {
			if (s == null || t == null) {
				return false;
			}
			int lastIndex = 0;
			for (int i = 0; i < s.length(); i++) {
				char si = s.charAt(i);
				int index = t.indexOf(si, lastIndex);
				if (index == -1) {
					return false;
				} else {
					lastIndex = index + 1;
				}
			}
			return true;
		}
		
		// 手动实现向后查找
		public boolean _isSubsequence(String s, String t) {
			if (s == null || t == null) {
				return false;
			}
			int index = 0;
			for (int i = 0; i < s.length(); i++) {
				char si = s.charAt(i);
				boolean siIsUnfounded = true;
				for (int j = index; j < t.length();	j++) {
					char tj = t.charAt(j);
					// 注意向后的指针要先移动，否则写在循环条件中或break后中断时可能导致不及时向后
					index++;
					if (si == tj) {
						siIsUnfounded = false;
						break;
					}
				}
				if (siIsUnfounded) {
					return false;
				}
			}
			return true;
		}
	}

	public static void main(String[] args) {
		String s = "leetcode";
		String t = "lyeytcode";
		String s_ = "abc";
		String t_ = "ahbgdc";
		System.out.println(new Is_Subsequence().new Solution().isSubsequence(s, t));
		System.out.println(new Is_Subsequence().new Solution().isSubsequence(s_, t_));
	}

}
