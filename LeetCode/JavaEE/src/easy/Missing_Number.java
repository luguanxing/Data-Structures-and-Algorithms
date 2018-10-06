package easy;

public class Missing_Number {

	class Solution {
		public int missingNumber(int[] nums) {
			long sum_full = 0;
			long sum_test = 0;
			for (int i = 0; i <= nums.length; i++) {
				sum_full += i;
			}
			for (int i = 0; i < nums.length; i++) {
				sum_test += nums[i];
			}
			return (int) (sum_full - sum_test);
		}
	}

	public static void main(String[] args) {
		int[] nums = { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
		System.out.println(new Missing_Number().new Solution().missingNumber(nums));
	}

}
