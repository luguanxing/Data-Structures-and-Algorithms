package medium;

import java.util.Arrays;

public class Rotate_Image {

	//��б�Գ�
    public void diagonal(int[][] matrix) {
    	int len = matrix.length;
    	for (int y = 0; y < len; y++) {
    		for (int x = 0; x < len - 1 - y; x++) {
    			int t = matrix[len - 1 - y][len - 1 - x];
    			matrix[len - 1 - y][len - 1 - x] = matrix[x][y];
    			matrix[x][y] = t;
    		}
    	}
    }
    
  //���·�ת
    public void horizontal(int[][] matrix) {
    	int len = matrix.length;
    	for (int y = 0; y < len/2; y++) {
    		for (int x = 0; x < len; x++) {
    			int t = matrix[y][x];
    			matrix[y][x] = matrix[len- 1 - y][x];
    			matrix[len- 1 - y][x] = t;
    		}
    	}
    }
	
    //������б�Գƣ������·�ת
    public void rotate(int[][] matrix) {
    	diagonal(matrix);
    	horizontal(matrix);
    }

//    �½����鷨
//    public void rotate(int[][] matrix) {
//        int len = matrix.length;
//        int mat[][] = new int[len][len];
//        int ct = 0;
//        for (int x = len - 1; x >= 0; x--)
//        	for (int y = 0; y < len; y++, ct++)
//        		mat[y][x] = matrix[ct / len][ct % len];
//        for (int i = 0; i < len; i++)
//        	for (int j = 0; j < len; j++)
//        		matrix[i][j] = mat[i][j];
//    }
	
	public static void main(String[] args) {
		int matrix[][] = {{1,2,3}, {4,5,6}, {7,8,9}};
		Rotate_Image main = new Rotate_Image();
		main.rotate(matrix);
		System.out.println(Arrays.deepToString(matrix));
	}

}
