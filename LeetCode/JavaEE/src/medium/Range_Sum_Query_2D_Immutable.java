package medium;

public class Range_Sum_Query_2D_Immutable {

	class NumMatrix {

		// 从左上到右下矩阵的内部求和
		int[][] sumToYX = null;

		public NumMatrix(int[][] matrix) {
			if (matrix == null || matrix.length == 0) {
				sumToYX = null;
				return;
			}
			int height = matrix.length;
			int width = matrix[0].length;
			sumToYX = new int[height][width];
			sumToYX[0][0] = matrix[0][0];
			for (int i = 1; i < width; i++) {
				sumToYX[0][i] = sumToYX[0][i - 1] + matrix[0][i];
			}
			for (int i = 1; i < height; i++) {
				sumToYX[i][0] += sumToYX[i - 1][0] + matrix[i][0];
			}
			for (int y = 1; y < height; y++) {
				for (int x = 1; x < width; x++) {
					sumToYX[y][x] = sumToYX[y - 1][x] + sumToYX[y][x - 1] - sumToYX[y - 1][x - 1] + matrix[y][x];
				}
			}
		}

		public int sumRegion(int y1, int x1, int y2, int x2) {
			// 新矩阵等于右下和减上方和减左方和补回左上方和(注意左上方如果是边界则左上方和为0)
			int sumDownRight = sumToYX[y2][x2];
			int sumUp = (y1 == 0 ? 0 : sumToYX[y1 - 1][x2]);
			int sumLeft = (x1 == 0 ? 0 : sumToYX[y2][x1 - 1]);
			int sumUpLeft = 0;
			if (y1 == 0 || x1 == 0) {
				sumUpLeft = 0;
			} else {
				sumUpLeft = sumToYX[y1 - 1][x1 - 1];
			}
			return sumDownRight - sumUp - sumLeft + sumUpLeft;
		}
	}

	public static void main(String[] args) {
		int[][] matrix = { { 3, 0, 1, 4, 2 }, { 5, 6, 3, 2, 1 }, { 1, 2, 0, 1, 5 }, { 4, 1, 0, 1, 7 },
				{ 1, 0, 3, 0, 5 } };
		int y1 = 2;
		int x1 = 1;
		int y2 = 4;
		int x2 = 3;
		int[][] matrix_ = { { -4, -5 } };
		int y1_ = 0;
		int x1_ = 1;
		int y2_ = 0;
		int x2_ = 1;
		System.out.println(new Range_Sum_Query_2D_Immutable().new NumMatrix(matrix).sumRegion(y1, x1, y2, x2));
		System.out.println(new Range_Sum_Query_2D_Immutable().new NumMatrix(matrix_).sumRegion(y1_, x1_, y2_, x2_));
	}

}
