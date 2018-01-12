package easy;

public class Hamming_Distance {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		System.out.println(hammingDistance(1, 4));
	}
	
    public static int hammingDistance(int x, int y) {
    	int sum = 0;
    	while (x>0 || y>0) {
    		int a = x % 2;
    		int b = y % 2;
    		if (a != b)
    			sum++;
    		x = x >> 1;
    		y = y >> 1;
		}
		return sum;
    }
    
//    public static int hammingDistance(int x, int y) {
//    	String s1 = Integer.toBinaryString(x);
//    	String s2 = Integer.toBinaryString(y);
//    	int sum = 0;
//    	while (s1.length() > 0 || s2.length() > 0) {
//			char a = (s1.length()>0) ? s1.charAt(s1.length()-1) : '0';
//			char b = (s2.length()>0) ? s2.charAt(s2.length()-1) : '0';
//	    	System.out.println(a + " " + b);
//	    	if (a != b)
//	    		sum++;
//	    	if (s1.length()>0)
//	    		s1 = s1.substring(0, s1.length() - 1);
//	    	if (s2.length()>0)
//	    		s2 = s2.substring(0, s2.length() - 1);
//		}
//		return sum;
//    }

}
