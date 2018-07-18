package easy;

public class Add_Strings {

	class Solution {
	    public String addStrings(String num1, String num2) {
	        StringBuilder sb1 = new StringBuilder(num1).reverse();
	        StringBuilder sb2 = new StringBuilder(num2).reverse();
	        StringBuilder sb3 = new StringBuilder();
	        int len = Math.max(sb1.length(), sb2.length());
	        while (sb1.length() < len) {
	        	sb1.append('0');
	        }
	        while (sb2.length() < len) {
	        	sb2.append('0');
	        }
	        while (sb3.length() < len) {
	        	sb3.append('0');
	        }
	        int next = 0;
	        for (int i = 0; i < len; i++) {
	        	int a = sb1.charAt(i) - '0';
	        	int b = sb2.charAt(i) - '0';
	        	int c = a + b + next;
	        	next = c / 10;
	        	sb3.setCharAt(i, (char)((c % 10) + '0'));
	        }
	        if (next != 0) {
	        	sb3.append('1');
	        }  
	    	return sb3.reverse().toString();
	    }
	}
	
	public static void main(String[] args) {
		Add_Strings main = new Add_Strings();
		String num1 = "1022";
		String num2 = "311";
		System.out.println(main.new Solution().addStrings(num1, num2));
	}

}
