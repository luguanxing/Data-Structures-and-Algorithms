package easy;

public class Binary_Search {

	class Solution {
		public int search(int[] nums, int target) {
			if (nums == null || nums.length == 0) {
				return -1;
			}
			if (target < nums[0] || nums[nums.length - 1] < target) {
				return -1;
			}
			// 左闭右开
			int left = 0;
			int right = nums.length;
			while (left <= right) {
				int middle = (left + right) / 2;
				if (nums[middle] == target) {
					return middle;
				} else if (nums[middle] < target) {
					left = middle + 1;
				} else {
					right = middle - 1;
				}
			}
			return -1;
		}
	}

	public static void main(String[] args) {
		int[] nums = { -1, 0, 3, 5, 9, 12 };
		int target = 13;
		System.out.println(new Binary_Search().new Solution().search(nums, target));
	}

}
