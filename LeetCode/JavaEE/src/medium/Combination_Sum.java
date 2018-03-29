package medium;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

public class Combination_Sum {

	class Solution {

		List<List<Integer>> allResult = new ArrayList<>();

		List<Integer> curResult = new ArrayList<>();

		public void checkResult(int[] candidates, int index, int target) {
			if (target == 0) {
				List<Integer> temp = new ArrayList<>(curResult);
				allResult.add(temp);
				return;
			}
			if (index >= candidates.length) {
				return;
			}
			int curNum = candidates[index];
			if (curNum > target) {
				// 不要这个数
				checkResult(candidates, index + 1, target);
			} else {
				// 还要这个数
				curResult.add(curNum);
				checkResult(candidates, index, target - curNum);
				curResult.remove(curResult.size() - 1);
				// 要下个数了
				curResult.add(curNum);
				checkResult(candidates, index + 1, target - curNum);
				curResult.remove(curResult.size() - 1);
				// 不要这个数
				checkResult(candidates, index + 1, target);
			}
		}

		public List<List<Integer>> combinationSum(int[] candidates, int target) {
			checkResult(candidates, 0, target);
			Set<List<Integer>> set = new HashSet();
			for (List<Integer> result : allResult) {
				set.add(result);
			}
			List<List<Integer>> temp = new ArrayList<>();
			for (List<Integer> result : set) {
				temp.add(result);
			}
			return temp;
		}

	}

	public static void main(String[] args) {
		int[] array = { 8, 7, 4, 3 };
		System.out.println(new Combination_Sum().new Solution().combinationSum(array, 11));
	}

}
