package easy;

public class First_Unique_Character_in_a_String {

	class Solution {
	    public int firstUniqChar(String s) {
	        if (s == null) {
	        	return -1;
	        }
	        int[] characters = new int[26];
	        for (int i = 0; i < s.length(); i++) {
	        	char character = s.charAt(i);
	        	characters[Character.toLowerCase(character)-'a']++;
	        }
	        for (int i = 0; i < s.length(); i++) {
	        	char character = s.charAt(i);
	        	if (characters[Character.toLowerCase(character)-'a'] == 1) {
	        		return i;
	        	}
	        }
	        return -1;
	    }
	}
	
	public static void main(String[] args) {
		String s = "loveleetcode";
		System.out.println(new First_Unique_Character_in_a_String().new Solution().firstUniqChar(s));
	}
	
}
