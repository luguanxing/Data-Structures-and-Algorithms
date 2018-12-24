package easy;


public class Island_Perimeter {

    class Solution {
        public int islandPerimeter(int[][] grid) {
            int height = grid.length;
            int width = grid[0].length;
            int[][] sumGrid = new int[height][width];
            int res = 0;
            for (int y = 0; y < height; y++) {
                for (int x = 0; x < width; x++) {
                    if (grid[y][x] == 1) {
                        int sum = 0;
                        if (y == 0) {
                            sum++;
                        } else {
                            if (grid[y - 1][x] == 0) {
                                sum++;
                            }
                        }
                        if (y == height - 1) {
                            sum++;
                        } else {
                            if (grid[y + 1][x] == 0) {
                                sum++;
                            }
                        }
                        if (x == 0) {
                            sum++;
                        } else {
                            if (grid[y][x - 1] == 0) {
                                sum++;
                            }
                        }
                        if (x == width - 1) {
                            sum++;
                        } else {
                            if (grid[y][x + 1] == 0) {
                                sum++;
                            }
                        }
                        sumGrid[y][x] = sum;
                    }
                }
            }
            for (int y = 0; y < height; y++) {
                for (int x = 0; x < width; x++) {
                    res += sumGrid[y][x];
                }
            }
            return res;
        }
    }

    public static void main(String[] args) {
        int[][] grid = { { 0, 1, 0, 0 }, { 1, 1, 1, 0 }, { 0, 1, 0, 0 }, { 1, 1, 0, 0 } };
        System.out.println(new Island_Perimeter().new Solution().islandPerimeter(grid));
    }

}
