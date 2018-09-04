package medium;

public class _01_Matrix {

    class Solution {
        public int[][] updateMatrix(int[][] matrix) {
            int height = matrix.length;
            int width = matrix[0].length;
            // 提交也超时，可用Math.min(width, height) + 10
            for (int n = 0; n < Math.max(width, height); n++) {
                for (int y = 0; y < height; y++) {
                    for (int x = 0; x < width; x++) {
                        if (matrix[y][x] != 0) {
                            int up = y == 0 ? Integer.MAX_VALUE : matrix[y - 1][x];
                            int down = y == height - 1 ? Integer.MAX_VALUE : matrix[y + 1][x];
                            int left = x == 0 ? Integer.MAX_VALUE : matrix[y][x - 1];
                            int right = x == width - 1 ? Integer.MAX_VALUE : matrix[y][x + 1];
                            if (up * down * left * right == 0) {
                                matrix[y][x] = 1;
                            } else {
                                matrix[y][x] = Math.min(Math.min(up, down), Math.min(left, right)) + 1;
                            }
                        }
                    }
                }
            }
            return matrix;
        }
    }

    // 使用bfs超时
    class Solution_bfs {
        int height = 0;
        int width = 0;
        int dis = width + height;
        boolean[][] state = null;

        private void bfsCheck(int[][] matrix, int y, int x, int step) {
            if (y < 0 || y >= height || x < 0 || x >= width) {
                return;
            }
            if (step > height + width) {
                return;
            }
            if (state[y][x] == true) {
                return;
            }
            if (matrix[y][x] == 0) {
                if (step < dis) {
                    dis = step;
                } else {
                    return;
                }
            }
            state[y][x] = true;
            bfsCheck(matrix, y - 1, x, step + 1);
            bfsCheck(matrix, y + 1, x, step + 1);
            bfsCheck(matrix, y, x + 1, step + 1);
            bfsCheck(matrix, y, x - 1, step + 1);
            state[y][x] = false;
        }

        public int[][] updateMatrix(int[][] matrix) {
            if (matrix == null || matrix.length == 0 || matrix[0] == null || matrix[0].length == 0) {
                return null;
            }
            height = matrix.length;
            width = matrix[0].length;
            for (int y = 0; y < height; y++) {
                for (int x = 0; x < width; x++) {
                    if (matrix[y][x] == 1) {
                        dis = width + height;
                        state = new boolean[height][width];
                        bfsCheck(matrix, y, x, 0);
                        matrix[y][x] = dis;
                    }
                }
            }
            return matrix;
        }
    }

    public static void main(String[] args) {
        int[][] matrix = { { 0, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 } };
        new _01_Matrix().new Solution().updateMatrix(matrix);
    }

}
