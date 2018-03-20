package test.huawei;
import java.util.Arrays;

public class Main {

	public class Solution {
		/**
		 * 交换数组里n和0的位置
		 * 
		 * @param array
		 *            数组
		 * @param len
		 *            数组长度
		 * @param n
		 *            和0交换的数
		 */
		public void swapWithZero(int[] array, int len, int n) {
			Main.SwapWithZero(array, len, n);
		}

		public void sort(int[] array, int len) {
			int maxPos = len - 1;
			// 选择排序
			while (maxPos >= 0) {
				// 先将0放到放到第zeroPos位
				Main.SwapWithZero(array, len, array[maxPos]);
				int max = -1;
				// 找出最大放到第zeroPos位
				for (int i = maxPos; i >= 0; i--) {
					if (array[i] > max) {
						max = array[i];
					}
				}
				// 向前推进(最终从小到大)
				Main.SwapWithZero(array, len, max);
				maxPos--;
			}
		}

	}

	public static void SwapWithZero(int[] array, int len, int n) {
		int zeroPos = 0;
		int targetPos = 0;
		for (int i = 0; i < len; i++) {
			if (array[i] == 0) {
				zeroPos = i;
			}
			if (array[i] == n) {
				targetPos = i;
			}
		}
		int tmp = 0;
		tmp = array[zeroPos];
		array[zeroPos] = array[targetPos];
		array[targetPos] = tmp;
	}

	public static void main(String[] args) {
		int[] array = { 1, 3, 2, 0, 5, 4, 6 };
		new Main().new Solution().sort(array, array.length);
		System.out.println(Arrays.toString(array));
	}

}