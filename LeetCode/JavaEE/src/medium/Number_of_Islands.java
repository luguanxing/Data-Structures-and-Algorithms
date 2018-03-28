package medium;

public class Number_of_Islands {

	class Solution {
		int count = 0;
		
		public void bfsDestroyLand(int y, int x, char[][] grid) {
			if (y < 0 || y >= grid.length) {
				return;
			}
			if (x < 0 || x >= grid[0].length) {
				return;
			}
			if (grid[y][x] == '0') {
				return;
			}
			grid[y][x] = '0';
			bfsDestroyLand(y-1, x, grid);
			bfsDestroyLand(y+1, x, grid);
			bfsDestroyLand(y, x-1, grid);
			bfsDestroyLand(y, x+1, grid);
		}
		
		public int numIslands(char[][] grid) {
			for (int y = 0; y < grid.length; y++) {
				for (int x = 0; x < grid[y].length; x++) {
					if (grid[y][x] == '1') {
						bfsDestroyLand(y, x, grid);
						count++;
					}
				}
			}
			return count;
		}
	}

}
