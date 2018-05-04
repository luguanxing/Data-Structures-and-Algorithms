package medium;

import java.util.Arrays;

public class Search_for_a_Range {

	class Solution {
		public int[] searchRange(int[] nums, int target) {
			int[] result = { -1, -1 };
			int isExist = Arrays.binarySearch(nums, 0, nums.length, target);
			if (isExist < 0) {
				return result;
			}
			// 左闭右闭区间
			int left = Arrays.binarySearch(nums, 0, nums.length, target);
			int right = Arrays.binarySearch(nums, 0, nums.length, target);
			// 确定左边界,逐渐往左逼近
			while (nums[left] == target) {
				// 如果左边还有该target，继续往左二分查找，否则结束
				if (0 < left && nums[left - 1] == target) {
					left = Arrays.binarySearch(nums, 0, left, target);
					continue;
				} else {
					result[0] = left;
					break;
				}
			}
			// 确定右边界,逐渐往右逼近
			while (nums[right] == target) {
				// 如果右边还有该target，继续往右二分查找，否则结束
				if (right < nums.length - 1 && nums[right + 1] == target) {
					right = Arrays.binarySearch(nums, right + 1, nums.length, target);
					continue;
				} else {
					result[1] = right;
					break;
				}
			}
			return result;
		}
	}

	public static void main(String[] args) {
		int[] nums = { 5, 7, 7, 8, 8, 10 };
		int target = 10;
		System.out.println(Arrays.toString(new Search_for_a_Range().new Solution().searchRange(nums, target)));
	}

}
