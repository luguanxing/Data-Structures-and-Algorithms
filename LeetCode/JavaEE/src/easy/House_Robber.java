package easy;

public class House_Robber {

	class Solution {
		public int rob(int[] nums) {
			if (nums == null || nums.length == 0) {
				return 0;
			}
			if (nums.length == 1) {
				return nums[0];
			}
			// maxDp[i]指到第i间时的最大价值，只需比较并取maxDp[i-2]+nums[i]和maxDp[i - 1]的较大值
			int[] maxDp = new int[nums.length];
			maxDp[0] = nums[0];
			maxDp[1] = Math.max(nums[0], nums[1]);
			for (int i = 2; i < nums.length; i++) {
				maxDp[i] = Math.max(maxDp[i - 2] + nums[i], maxDp[i - 1]);
			}
			return maxDp[nums.length - 1];
		}
	}

	public static void main(String[] args) {
		int[] nums = { 2, 7, 9, 3, 1 };
		System.out.println(new House_Robber().new Solution().rob(nums));
	}

}
