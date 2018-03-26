import java.util.Scanner;

/*
一种双核CPU的两个核能够同时的处理任务，现在有n个已知数据量的任务需要交给CPU处理，
假设已知CPU的每个核1秒可以处理1kb，每个核同时只能处理一项任务。n个任务可以按照任
意顺序放入CPU进行处理，现在需要设计一个方案让CPU处理完这批任务所需的时间最少，
求这个最小的时间。 
 */

public class Main {

	// 解决背包问题
	public static int packeting(int[] w, int[] v, int c) {
		int n = w.length;
		if (n == 0)
			return 0;
		// maxValue[n][c]表示在容量为c情况下只能拿前n件物品时最大值
		int[][] maxValue = new int[n][c + 1];
		for (int j = 0; j <= c; j++)
			maxValue[0][j] = (j >= w[0] ? v[0] : 0);
		for (int i = 1; i < n; i++)
			for (int j = 0; j <= c; j++) {
				// 不拿第i件物品时
				int noTakeItemI = maxValue[i - 1][j];
				maxValue[i][j] = noTakeItemI;
				if (j >= w[i]) {
					// 能拿且拿第i件物品时
					int takeItemI = maxValue[i - 1][j - w[i]] + v[i];
					maxValue[i][j] = Math.max(noTakeItemI, takeItemI);
				}
			}
		return maxValue[n - 1][c];
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int packetValue = 0;
		int[] tasks = new int[n];
		for (int i = 0; i < n; i++) {
			tasks[i] = in.nextInt() / 1024;
			packetValue += tasks[i];
		}
		// 把时间分成两半，尽可能使两部分平均，所以让其中一半越多越好，最终变成背包问题
		int maxHalfPacketValue = packeting(tasks, tasks, packetValue / 2);
		System.out.println(Math.max(maxHalfPacketValue, packetValue - maxHalfPacketValue) * 1024);
	}

} 