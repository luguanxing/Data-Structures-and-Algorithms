
public class Palindrome_Number {

	public static void main(String[] args) {
		System.out.println(isPalindrome(1221));
	}
	
    public static boolean isPalindrome(int x) {
        String str = Integer.toString(x);
        int len = str.length();
    	for (int i = 0; i < len / 2; i++) {
    		if (str.charAt(i) != str.charAt(len - 1 -i))
    			return false;
    	}
    	return true;
    }
    
//    public static boolean isPalindrome(int x) {
//	    int temp =x;
//	    int ans =0;
//	    while(temp>0)
//	    {
//	        ans = ans*10+(temp%10);
//	        temp = temp/10;
//	    }
//	    return (ans == Math.abs(x));
//    }
    
}
