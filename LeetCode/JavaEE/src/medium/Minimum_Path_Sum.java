package medium;

public class Minimum_Path_Sum {

	class Solution {
		public int minPathSum(int[][] grid) {
			int height = grid.length;
			int width = grid[0].length;
			int[][] minSum = new int[height][width];
			minSum[0][0] = grid[0][0];
			for (int i = 1; i < width; i++) {
				minSum[0][i] = grid[0][i] + minSum[0][i-1];
			}
			for (int i = 1; i < height; i++) {
				minSum[i][0] = grid[i][0] + minSum[i-1][0];
			}
			for (int y = 1; y < height; y++) {
				for (int x = 1; x < width; x++) {
					minSum[y][x] = Math.min(minSum[y-1][x], minSum[y][x-1]) + grid[y][x];
				}
			}
			return minSum[height-1][width-1];
		}
	}

	public static void main(String[] args) {
		int[][] grid = {{1,3,1},{1,5,1},{4,2,1}};
		System.out.println(new Minimum_Path_Sum().new Solution().minPathSum(grid));
	}

}
