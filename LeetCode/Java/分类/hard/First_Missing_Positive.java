package hard;

public class First_Missing_Positive {

    public int firstMissingPositive(int[] nums) {
        boolean[] flags = new boolean[50000];
    	for (int i : nums) {
    		if (i > 0)
    			flags[i] = true;
		}
    	for (int i = 1; i <= flags.length; i++)
    		if (i > 0 && !flags[i])
    			return i;
    	return 0;
    }
	
	public static void main(String[] args) {
		First_Missing_Positive main = new First_Missing_Positive();
		System.out.println(main.firstMissingPositive(new int[] {3,4,-1,1}));
	}

}
