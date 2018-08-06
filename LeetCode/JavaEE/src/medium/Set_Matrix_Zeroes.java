package medium;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Set_Matrix_Zeroes {

	class Solution {
		public void setZeroes(int[][] matrix) {
			if (matrix == null) {
				return;
			}
			List<Integer> zeroRow = new ArrayList<>();
			List<Integer> zeroCol = new ArrayList<>();
			for (int y = 0; y < matrix.length; y++) {
				for (int x = 0; x < matrix[0].length; x++) {
					if (matrix[y][x] == 0) {
						zeroRow.add(y);
						zeroCol.add(x);
					}
				}
			}
			for (Integer x : zeroCol) {
				for (int i = 0; i < matrix.length; i++) {
					matrix[i][x] = 0;
				}
			}
			for (Integer y : zeroRow) {
				for (int i = 0; i < matrix[0].length; i++) {
					matrix[y][i] = 0;
				}
			}
		}
	}

	public static void main(String[] args) {
		int[][] matrix = { { 0, 1, 2, 0 }, { 3, 4, 5, 2 }, { 1, 3, 1, 5 } };
		for (int[] row : matrix) {
			System.out.println(Arrays.toString(row));
		}
		new Set_Matrix_Zeroes().new Solution().setZeroes(matrix);
		System.out.println();
		for (int[] row : matrix) {
			System.out.println(Arrays.toString(row));
		}
	}

}
