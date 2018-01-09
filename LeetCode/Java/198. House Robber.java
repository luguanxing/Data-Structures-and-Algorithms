package easy;

public class House_Robber {

    public int rob(int[] nums) {
        //设maxValue[x]表示考虑[0-x]最大的价值
    	//对于任意nums[i]>0状态方程f(x)=max{f(x-2)+nums[x], f(x-1)}
    	int[] maxValue = new int[nums.length+1];
    	maxValue[0] = 0;
    	for (int i = 1; i <= nums.length; i++) {
    		if (i - 2 >= 0) {
    			int robI = maxValue[i-2] + nums[i-1];
    			int noRobi = maxValue[i-1];
    			maxValue[i] = Math.max(robI, noRobi);
    		} else {
    			maxValue[i] = nums[0];
    		}
    	}
    	return maxValue[nums.length];
    }
	
	public static void main(String[] args) {
		int[] nums = {1};
		System.out.println(new House_Robber().rob(nums));
	}

}
