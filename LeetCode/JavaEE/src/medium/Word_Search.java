package medium;

public class Word_Search {

    class Solution {

        boolean isVisited[][] = null;
        int height = 0;
        int width = 0;

        public boolean exist(char[][] board, String word) {
            height = board.length;
            width = board[0].length;
            isVisited = new boolean[height][width];
            // 对矩阵内逐个点开头进行检查(BFS)
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (check(board, i, j, word)) {
                        return true;
                    }
                }
            }
            return false;
        }

        private boolean check(char[][] board, int i, int j, String word) {
            // 没有匹配字符了，成功
            if (word.isEmpty()) {
                return true;
            }
            // 越界了，失败
            if (i < 0 || i >= height || j < 0 || j >= width) {
                return false;
            }
            // 该点走过了，失败
            if (isVisited[i][j]) {
                return false;
            }
            // 该点未走过且首字符匹配上了，则向后BFS
            if (!isVisited[i][j] && (word.charAt(0) == board[i][j])) {
                isVisited[i][j] = true;
                // 将判断条件写在BFS函数内部，这样调用时就会简洁一些
                boolean checkNext = check(board, i - 1, j, word.substring(1))
                        || check(board, i, j - 1, word.substring(1)) || check(board, i + 1, j, word.substring(1))
                        || check(board, i, j + 1, word.substring(1));
                isVisited[i][j] = false;
                return checkNext;
            }
            return false;
        }

    }

    public static void main(String[] args) {
        char[][] board = { { 'A', 'B', 'C', 'E' }, { 'S', 'F', 'C', 'S' }, { 'A', 'D', 'E', 'E' } };
        String word = "ABCCED";
        System.out.println(new Word_Search().new Solution().exist(board, word));
    }

}
