package easy;

import java.util.Arrays;

public class Rotate_Array {

	class Solution {
		public void rotate(int[] nums, int k) {
			int len = nums.length;
			// 旋转长度整数倍和不旋转效果一样
			if (k > len) {
				k = k % len;
			}
			// 将前len-k位数复制到后，将后k位数复制到前面，从而完成旋转
			int[] result = new int[len];
			for (int i = 0; i < len - k; i++) {
				result[k + i] = nums[i];
			}
			for (int i = len - 1; i >= len - k; i--) {
				result[i - (len - k)] = nums[i];
			}
			// 改变引用的结果
			for (int i = 0; i < len; i++) {
				nums[i] = result[i];
			}
		}
	}

	public static void main(String[] args) {
		int[] nums = { 1, 2 };
		int k = 3;
		new Rotate_Array().new Solution().rotate(nums, k);
		System.out.println(Arrays.toString(nums));
	}

}
