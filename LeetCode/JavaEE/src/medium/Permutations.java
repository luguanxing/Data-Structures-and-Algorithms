package medium;

import java.util.ArrayList;
import java.util.List;

public class Permutations {

	class Solution {
		public List<List<Integer>> allResult = new ArrayList<>();

		public void genResult(List<Integer> curResult, List<Integer> leftNum) {
			if (leftNum.isEmpty()) {
				allResult.add(new ArrayList(curResult));
				return;
			}
			for (int i = 0; i < leftNum.size(); i++) {
				Integer curNum = leftNum.get(i);
				curResult.add(curNum);
				leftNum.remove(i);
				genResult(curResult, leftNum);
				curResult.remove(curNum);
				leftNum.add(i, curNum);
			}
		}

		public List<List<Integer>> permute(int[] nums) {
			if (nums == null) {
				return null;
			}
			List<Integer> numsList = new ArrayList<>();
			for (int num : nums) {
				numsList.add(num);
			}
			genResult(new ArrayList<>(), numsList);
			return allResult;
		}
	}

	public static void main(String[] args) {
		int[] nums = { 1, 2, 3 };
		System.out.println(new Permutations().new Solution().permute(nums));
	}

}
