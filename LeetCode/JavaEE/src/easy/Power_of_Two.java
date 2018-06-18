package easy;

public class Power_of_Two {

	class Solution {
	    public boolean isPowerOfTwo(int n) {
	    	if (n == 0 || n < 0) {
	    		return false;
	    	}
	        return (n - 1 & n) == 0;
	    }
	}
	
}
