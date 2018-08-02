package medium;

import java.util.ArrayList;
import java.util.List;

public class Spiral_Matrix {

	class Solution {
		public List<Integer> spiralOrder(int[][] matrix) {
			if (matrix == null) {
				return null;
			}
			int height = matrix.length;
			int width = height > 0 ? matrix[0].length : 0;
			int y = 0;
			int x = 0;
			int direction = 0;
			List<Integer> result = new ArrayList<>();
			while (0 <= x && x < width && 0 <= y && y < height && matrix[y][x] != Integer.MIN_VALUE) {
				result.add(matrix[y][x]);
				System.out.println("(" + y + "," + x + ")" + " -> " + matrix[y][x]);
				matrix[y][x] = Integer.MIN_VALUE;
				if (direction == 0) {
					x++;
					if (x >= width || matrix[y][x] == Integer.MIN_VALUE) {
						x--;
						y++;
						direction = 1;
					}
				} else if (direction == 1) {
					y++;
					if (y >= height || matrix[y][x] == Integer.MIN_VALUE) {
						y--;
						x--;
						direction = 2;
					}
				} else if (direction == 2) {
					x--;
					if (x < 0 || matrix[y][x] == Integer.MIN_VALUE) {
						x++;
						y--;
						direction = 3;
					}
				} else {
					y--;
					if (y < 0 || matrix[y][x] == Integer.MIN_VALUE) {
						x++;
						y++;
						direction = 0;
					}
				}
			}
			return result;
		}
	}

	public static void main(String[] args) {
		int[][] matrix = new int[3][3];
		// matrix[0] = new int[] { 1, 2, 3 };
		// matrix[1] = new int[] { 4, 5, 6 };
		// matrix[2] = new int[] { 7, 8, 9 };
		matrix[0] = new int[] { 1, 2, 3, 4 };
		matrix[1] = new int[] { 5, 6, 7, 8 };
		matrix[2] = new int[] { 9, 10, 11, 12 };
		System.out.println(new Spiral_Matrix().new Solution().spiralOrder(matrix));
	}

}
