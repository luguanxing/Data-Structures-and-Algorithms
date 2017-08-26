package easy;

public class Maximum_Subarray {

	public static void main(String[] args) {
		int[] nums = {-2,1,-3,4,-1,2,1,-5,4};
		System.out.println(maxSubArray(nums));
	}
	
    public static int maxSubArray(int[] nums) {
        if (nums == null || nums.length == 0)
        	return 0;
        int local = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.length; i++) {
        	local = Math.max(local+nums[i], nums[i]);	//�жϻ��۵���ǰ�Ĵ��ǵ�ǰ�Ĵ�,�����ǰ�Ĵ�ͷ���֮ǰ�Ļ���
        	max = Math.max(max, local);					//һֱȡ���
        }
        return max;
    }

}
