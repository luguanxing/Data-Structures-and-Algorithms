package easy;

public class Number_Complement {

	class Solution {
	    public int findComplement(int num) {
	    	String num_str = Integer.toBinaryString(num);
	    	String num_str2 = "";
	    	for (int i = 0; i < num_str.length(); i++) {
	    		if (num_str.charAt(i) == '0') {
	    			num_str2 += '1';
	    		} else {
	    			num_str2 += '0';
				}
	    	}
	    	Integer num2 = Integer.parseInt(num_str2, 2);
	        return num2;
	    }
	}
	
	public static void main(String[] args) {
		int num = 5;
		System.out.println(new Number_Complement().new Solution().findComplement(num));
	}
	
}
