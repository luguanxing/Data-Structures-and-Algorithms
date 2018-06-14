package easy;

import java.util.Arrays;

public class Move_Zeroes {

	class Solution {
		public void moveZeroes(int[] nums) {
			if (nums == null) {
				return;
			}
			// 把0移到后面，那么级把非0挤压到前面，index表示前面非0的序号
			int index = 0;
			for (int i = 0; i < nums.length; i++) {
				if (nums[i] != 0) {
					nums[index++] = nums[i];
				}
			}
			// 最后再补0
			for (int i = index; i < nums.length; i++) {
				nums[i] = 0;
			}
		}
	}

	public static void main(String[] args) {
		int[] nums = { 0, 1, 0, 3, 12 };
		new Move_Zeroes().new Solution().moveZeroes(nums);
		System.out.println(Arrays.toString(nums));
	}

}
