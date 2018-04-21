package medium;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Subsets_II {

	class Solution {
		Set<List<Integer>> set = new HashSet<>();

		public void check(int[] nums, List<Integer> curResult, int index) {
			if (index >= nums.length) {
				Collections.sort(curResult);
				set.add(curResult);
				return;
			}
			List<Integer> takeNum = new ArrayList<>(curResult);
			takeNum.add(nums[index]);
			check(nums, takeNum, index + 1);
			List<Integer> noTakeNum = new ArrayList<>(curResult);
			check(nums, noTakeNum, index + 1);
		}

		public List<List<Integer>> subsetsWithDup(int[] nums) {
			check(nums, new ArrayList<>(), 0);
			List<List<Integer>> result =  new ArrayList<>();
			for (List<Integer> list : set) {
				result.add(list);
			}
			return result;
		}
	}

	public static void main(String[] args) {
		int[] nums = { 4, 4, 4, 1, 4 };
		System.out.println(new Subsets_II().new Solution().subsetsWithDup(nums));
	}

}
