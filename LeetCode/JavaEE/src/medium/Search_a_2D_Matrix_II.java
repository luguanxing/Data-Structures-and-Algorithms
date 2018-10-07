package medium;

public class Search_a_2D_Matrix_II {

	class Solution {
		public boolean searchMatrix(int[][] matrix, int target) {
			if (matrix == null || matrix.length == 0 || matrix[0] == null || matrix[0].length == 0) {
				return false;
			}
			int height = matrix.length;
			int width = matrix[0].length;
			int x = width - 1;
			int y = 0;
			while (0 <= x && y < height) {
				if (matrix[y][x] == target) {
					return true;
				}
				if (matrix[y][x] < target) {
					// 左边都更小，无需考虑，剔除行
					y++;
				} else {
					// 下面都更大，无需考虑，剔除列
					x--;
				}
			}
			return false;
		}
	}

	public static void main(String[] args) {
		int[][] matrix = {
				  {1,   4,  7, 11, 15},
				  {2,   5,  8, 12, 19},
				  {3,   6,  9, 16, 22},
				  {10, 13, 14, 17, 24},
				  {18, 21, 23, 26, 30}
				};
		int target = 27;
		System.out.println(new Search_a_2D_Matrix_II().new Solution().searchMatrix(matrix, target));
	}

}
