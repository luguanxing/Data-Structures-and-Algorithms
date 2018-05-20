package easy;

public class Reverse_Vowels_of_a_String {

	class Solution {
		public boolean isVowel(char character) {
			char c = Character.toLowerCase(character);
			return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
		}
		
		public String reverseVowels(String s) {
			if (s == null) {
				return null;
			}
			char[] s_chars = s.toCharArray();
			int left = 0;
			int right = s.length() - 1;
			while (left < right) {
				while (left < s.length() && !isVowel(s_chars[left])) {
					left++;
				}
				while (0 <= right && !isVowel(s_chars[right])) {
					right--;
				}
				if (left < right) {
					char temp = s_chars[left];
					s_chars[left] = s_chars[right];
					s_chars[right] = temp;
					left++;
					right--;
				}
			}
			s = new String(s_chars);
			return s;
		}
	}

	public static void main(String[] args) {
		String s = "leetcode";
		System.out.println(new Reverse_Vowels_of_a_String().new Solution().reverseVowels(s));
	}
	
}
