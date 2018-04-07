package medium;

import java.util.HashSet;
import java.util.Set;

public class Longest_Substring_Without_Repeating_Characters {

	class Solution {
		public int lengthOfLongestSubstring(String s) {
			int maxLen = 0;
			int left = 0;
			int right = 0;
			Set<Character> set = new HashSet();
			// 两个指针(左闭右开)，如果右边的发现重复则左边的移动直到不重复为止
			while (left < s.length()) {
				// 如果右边未到尽头，不断向右探测，否则左边移动直到结束
				if (right < s.length()) {
					char curChar = s.charAt(right);
					if (set.contains(curChar)) {
						set.remove(s.charAt(left));
						left++;
					} else {
						set.add(curChar);
						right++;
					}
				} else {
					set.remove(s.charAt(left));
					left++;
				}
				maxLen = Math.max(maxLen, right - left);
			}
			return maxLen;
		}
	}

	public static void main(String[] args) {
		String s = "pwwkew";
		System.out.println(
				new Longest_Substring_Without_Repeating_Characters().new Solution().lengthOfLongestSubstring(s));
	}

}
