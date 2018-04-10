package medium;

import java.util.ArrayList;
import java.util.List;

public class Subsets {

	class Solution {
		List<List<Integer>> result = new ArrayList<>();

		public void printSubset(int[] nums, List<Integer> curResult, int index) {
			if (index >= nums.length) {
				result.add(curResult);
				return;
			}
			// 将nums[index]放入
			ArrayList<Integer> takeNum = new ArrayList<>(curResult);
			takeNum.add(nums[index]);
			printSubset(nums, takeNum, index + 1);
			// 不将nums[index]放入
			ArrayList<Integer> noTakeNum = new ArrayList<>(curResult);
			printSubset(nums, noTakeNum, index + 1);
		}

		public List<List<Integer>> subsets(int[] nums) {
			printSubset(nums, new ArrayList<>(), 0);
			return result;
		}
	}

	public static void main(String[] args) {
		int[] nums = { 1, 2, 3 };
		System.out.println(new Subsets().new Solution().subsets(nums));
	}

}
