package medium;

public class Maximal_Square {

	class Solution {
		public int maximalSquare(char[][] matrix) {
			if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
				return 0;
			}
			int[][] state = new int[matrix.length][matrix[0].length];
			for (int i = 0; i < matrix.length; i++) {
				state[i][0] = matrix[i][0] == '1' ? 1 : 0;
			}
			for (int i = 0; i < matrix[0].length; i++) {
				state[0][i] = matrix[0][i] == '1' ? 1 : 0;
			}
			for (int i = 1; i < matrix.length; i++) {
				for (int j = 1; j < matrix[0].length; j++) {
					if (matrix[i][j] == '1') {
						// 以正方形右下角的点来考虑，如果左边、上边、左上边都能组成正方形右下角，那就按短板效应加一变成大一点的正方形
						int up = state[i - 1][j];
						int left = state[i][j - 1];
						int leftUp = state[i - 1][j - 1];
						state[i][j] = Math.min(Math.min(up, left), leftUp) + 1;
					} else {
						// 当前为0不可能组成正方形右下角
						state[i][j] = 0;
					}
				}
			}
			int max = 0;
			for (int i = 0; i < matrix.length; i++) {
				for (int j = 0; j < matrix[0].length; j++) {
					if (state[i][j] > max) {
						max = state[i][j];
					}
				}
			}
			return max * max;
		}
	}

	public static void main(String[] args) {
		char[][] matrix = new char[4][5];
		matrix[0] = new char[] { '1', '0', '1', '0', '0' };
		matrix[1] = new char[] { '1', '0', '1', '1', '1' };
		matrix[2] = new char[] { '1', '1', '1', '1', '1' };
		matrix[3] = new char[] { '1', '0', '0', '1', '0' };
		System.out.println(new Maximal_Square().new Solution().maximalSquare(matrix));
	}

}
