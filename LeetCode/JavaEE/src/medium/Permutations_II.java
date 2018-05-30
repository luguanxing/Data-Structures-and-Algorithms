package medium;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Permutations_II {

	class Solution {
		public List<List<Integer>> allResult = new ArrayList<>();

		public void genResult(List<Integer> curResult, List<Integer> leftNum) {
			if (leftNum.isEmpty()) {
				allResult.add(new ArrayList(curResult));
				return;
			}
			for (int i = 0; i < leftNum.size(); i++) {
				Integer curNum = leftNum.get(i);
				curResult.add(curResult.size(), curNum);
				leftNum.remove(i);
				genResult(curResult, leftNum);
				curResult.remove(curResult.size() - 1);
				leftNum.add(i, curNum);
			}
		}

		public List<List<Integer>> permuteUnique(int[] nums) {
			if (nums == null) {
				return null;
			}
			List<Integer> numsList = new ArrayList<>();
			for (int num : nums) {
				numsList.add(num);
			}
			genResult(new ArrayList<>(), numsList);
			Set<List<Integer>> set = new HashSet<>(allResult);
			allResult.clear();
			for (List<Integer> result : set) {
				allResult.add(result);
			}
			return allResult;
		}
	}

	public static void main(String[] args) {
		int[] nums = { 1, 1, 2, 2 };
		System.out.println(new Permutations_II().new Solution().permuteUnique(nums));
	}

}
