package medium;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Combinations {

	class Solution {
		List<List<Integer>> res = new ArrayList<>();
		List<Integer> curRes =  new ArrayList<>();
		//从n选出k组合放入res
		public void comb(int n, int k) {
			if (k == 0) {
				ArrayList<Integer> temp = new ArrayList<>();
				temp.addAll(curRes);
				res.add(temp);
				return;
			}
			if (n == 0) {
				return;
			}	
			//要n，则从n-1中选k-1
			curRes.add(n);
			comb(n-1, k-1);	
			//不要n，则从n-1中选k
			curRes.remove(curRes.size()-1);
			comb(n-1, k);
		}
		public List<List<Integer>> combine(int n, int k) {
			comb(n,k);
			return res;
		}
	}
	
	//附排列的计算
	List<Integer> curPerRes =  new ArrayList<>();
	public void permutation(List<Integer> list) {
		if (list.isEmpty()) {
			for (Integer i : curPerRes) {
				System.out.print(i + " ");
			}
			System.out.println();
			return;
		}
		for (int i = 0; i < list.size(); i++) {
			Integer cur = list.get(i);
			curPerRes.add(cur);
			list.remove(i);
			permutation(list);
			list.add(i, cur);
			curPerRes.remove(curPerRes.size()-1);
		}
	}

	public static void main(String[] args) {
		Combinations main = new Combinations();
		List<List<Integer>> combine = main.new Solution().combine(6, 3);
		//排列
		System.out.println("排列:");
		for (List<Integer> list : combine) {
			System.out.println(list);
		}
		//组合
		System.out.println("组合:");
		for (List<Integer> list : combine) {
			main.permutation(list);
		}
	}

}
