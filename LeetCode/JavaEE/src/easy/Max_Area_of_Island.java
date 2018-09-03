package easy;

public class Max_Area_of_Island {

    class Solution {
        int max = 0;
        int current = 0;
        int height = 0;
        int width = 0;

        public void checkAndDestory(int[][] grid, int y, int x) {
            if (y < 0 || y >= height) {
                return;
            }
            if (x < 0 || x >= width) {
                return;
            }
            if (grid[y][x] == 0) {
                return;
            }
            grid[y][x] = 0;
            current++;
            if (max < current) {
                max = current;
            }
            checkAndDestory(grid, y - 1, x);
            checkAndDestory(grid, y + 1, x);
            checkAndDestory(grid, y, x - 1);
            checkAndDestory(grid, y, x + 1);
        }

        public int maxAreaOfIsland(int[][] grid) {
            if (grid == null || grid.length == 0 || grid[0] == null || grid[0].length == 0) {
                return 0;
            }
            height = grid.length;
            width = grid[0].length;
            for (int y = 0; y < height; y++) {
                for (int x = 0; x < width; x++) {
                    if (grid[y][x] == 1) {
                        current = 0;
                        checkAndDestory(grid, y, x);
                    }
                }
            }
            return max;
        }
    }
    
    
    public static void main(String[] args) {
        int[][] grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                {0,0,0,0,0,0,0,1,1,0,0,0,0}};
        System.out.println(new Max_Area_of_Island().new Solution().maxAreaOfIsland(grid));
    }
    

}
