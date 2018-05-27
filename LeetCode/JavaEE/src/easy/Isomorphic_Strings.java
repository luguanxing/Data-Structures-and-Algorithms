package easy;

import java.util.HashMap;
import java.util.Map;

public class Isomorphic_Strings {

	class Solution {
	    public boolean isIsomorphic(String s, String t) {
	        if (s == null || t == null || s.length() != t.length()) {
	        	return false;
	        }
        	Map<Character, Character> mapS2T = new HashMap<>();
        	Map<Character, Character> mapT2S = new HashMap<>();
	        for (int i = 0; i < s.length(); i++) {
	        	char charSi = s.charAt(i);
	        	char charTi = t.charAt(i);
	        	mapS2T.put(charSi, charTi);
	        	mapT2S.put(charTi, charSi);
	        }
	        StringBuilder sbS2T = new StringBuilder();
	        for (int i = 0; i < s.length(); i++) {
	        	char charSi = s.charAt(i);
	        	if (mapS2T.get(charSi) == null) {
	        		sbS2T.append(charSi);
	        	} else {
	        		sbS2T.append(mapS2T.get(charSi));
	        	}
	        }
	        StringBuilder sbT2S = new StringBuilder();
	        for (int i = 0; i < t.length(); i++) {
	        	char charTi = t.charAt(i);
	        	if (mapT2S.get(charTi) == null) {
	        		sbT2S.append(charTi);
	        	} else {
	        		sbT2S.append(mapT2S.get(charTi));
	        	}
	        }
	        if (sbS2T.toString().equals(t) && sbT2S.toString().equals(s)) {
	        	return true;
	        }
	    	return false;
	    }
	}
	
	public static void main(String[] args) {
		String s = "paper";
		String  t = "title";
		System.out.println(new Isomorphic_Strings().new Solution().isIsomorphic(s, t));
	}
	
}
