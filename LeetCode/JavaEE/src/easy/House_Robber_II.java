package easy;

import java.util.Arrays;

public class House_Robber_II {
	class Solution {
		public int rob_noCircle(int[] nums) {
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
			//System.out.println(Arrays.toString(nums));
			//System.out.println(Arrays.toString(maxDp));
			if (nums.length > 2) {
				// 如果既要头又要尾说明冲突，取去掉头或尾的较大值
				if (maxDp[nums.length - 3] + nums[nums.length - 1] == maxDp[nums.length - 1] && maxDp[0] == nums[0]) {
					int[] numsWithoutTail = Arrays.copyOfRange(nums, 0, nums.length - 1);
					int[] numsWithoutHead = Arrays.copyOfRange(nums, 1, nums.length);
					return Math.max(rob_noCircle(numsWithoutTail), rob_noCircle(numsWithoutHead));
				}
			}
			return maxDp[nums.length - 1];
		}
	}

	public static void main(String[] args) {
		int[] nums = { 1, 2, 3, 1 };
		System.out.println(new House_Robber_II().new Solution().rob(nums));
	}
}
