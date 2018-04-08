package easy;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Pascals_Triangle {

	class Solution {
		public List<List<Integer>> generate(int numRows) {
			List<List<Integer>> results = new ArrayList<>();
			if (numRows == 0) {
				return results;
			}
			// 向下打印三角
			for (int y = 0; y < numRows; y++) {
				Integer[] line = new Integer[y + 1];
				if (y == 0) {
					line[0] = 1;
				} else {
					line[0] = 1;
					line[y] = 1;
					for (int x = 1; x < y; x++) {
						line[x] = results.get(results.size()-1).get(x-1) + results.get(results.size()-1).get(x);
					}
				}
				results.add(Arrays.asList(line));
			}
			return results;
		}
	}
	
	public static void main(String[] args) {
		System.out.println(new Pascals_Triangle().new Solution().generate(5));
	}

}
