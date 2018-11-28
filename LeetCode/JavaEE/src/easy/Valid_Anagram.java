package easy;

import java.util.HashMap;
import java.util.Map;

public class Valid_Anagram {

	// 除了用map还可以用桶int[26]或者排序方法
	class Solution {
		public boolean isAnagram(String s, String t) {
			Map<Character, Integer> map = new HashMap<>();
			for (int i = 0; i < s.length(); i++) {
				char c = s.charAt(i);
				if (!map.containsKey(c)) {
					map.put(c, 1);
				} else {
					map.put(c, map.get(c) + 1);
				}
			}
			for (int i = 0; i < t.length(); i++) {
				char c = t.charAt(i);
				if (!map.containsKey(c)) {
					return false;
				} else {
					map.put(c, map.get(c) - 1);
				}
			}
			for (Character c : map.keySet()) {
				Integer count = map.get(c);
				if (count != 0) {
					return false;
				}
			}
			return true;
		}
	}
	
	public static void main(String[] args) {
		String s = "rat";
		String t = "car";
		System.out.println(new Valid_Anagram().new Solution().isAnagram(s, t));
	}

}
