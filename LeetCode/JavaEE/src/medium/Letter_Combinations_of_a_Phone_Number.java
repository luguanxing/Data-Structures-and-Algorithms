package medium;

import java.util.LinkedList;
import java.util.List;

public class Letter_Combinations_of_a_Phone_Number {

	class Solution {
		List<String> allResult = new LinkedList<>();

		// 更好的方式是写一个数组，里面有"abc","pqrs"这些用来组合，手动写规则比较麻烦的
		public void pressKey(StringBuilder currentKeys, StringBuilder remainKeys) {
			if (remainKeys.length() == 0) {
				allResult.add(currentKeys.toString());
				return;
			}
			char key = remainKeys.charAt(0);
			int flag = 0;
			// 遇到8和9按键向后退1位，因为7按键有4个字符
			if (key == '8' || key == '9') {
				flag = 1;
			}
			StringBuilder currentKeys1 = new StringBuilder(currentKeys).append((char) (3 * (key - '2') + 'a' + flag));
			StringBuilder currentKeys2 = new StringBuilder(currentKeys).append((char) (3 * (key - '2') + 'b' + flag));
			StringBuilder currentKeys3 = new StringBuilder(currentKeys).append((char) (3 * (key - '2') + 'c' + flag));
			StringBuilder remainKeys1 = new StringBuilder(remainKeys).deleteCharAt(0);
			StringBuilder remainKeys2 = new StringBuilder(remainKeys).deleteCharAt(0);
			StringBuilder remainKeys3 = new StringBuilder(remainKeys).deleteCharAt(0);
			pressKey(currentKeys1, remainKeys1);
			pressKey(currentKeys2, remainKeys2);
			pressKey(currentKeys3, remainKeys3);
			// 7按键和9按键有4个字符，都要再输出1个字符
			if (key == '7' || key == '9') {
				StringBuilder currentKeys4 = currentKeys.append((char) (3 * (key - '2') + 'd' + flag));
				StringBuilder remainKeys4 = new StringBuilder(remainKeys).deleteCharAt(0);
				pressKey(currentKeys4, remainKeys4);
			}

		}

		public List<String> letterCombinations(String digits) {
			if (digits == null) {
				return null;
			}
			if (digits.isEmpty()) {
				return allResult;
			}
			pressKey(new StringBuilder(""), new StringBuilder(digits));
			return allResult;
		}
	}

	public static void main(String[] args) {
		String digits = "";
		System.out.println(new Letter_Combinations_of_a_Phone_Number().new Solution().letterCombinations(digits));
	}

}
