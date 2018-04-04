import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/*
	给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输出结果。输入值小于1000。
	如，输入为10, 程序应该输出结果为2。（共有两对质数的和为10,分别为(5,5),(3,7)）
*/

public class Main {

	public static Set<Integer> primes = new HashSet();

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		// 保存素数集合
		for (int i = 2; i <= 1000; i++) {
			boolean isPrime = true;
			for (int j = 2; j <= (int) Math.sqrt(i); j++) {
				if (i % j == 0) {
					isPrime = false;
					break;
				}
			}
			if (isPrime) {
				primes.add(i);
			}
		}
		// 计算素数和
		int n = in.nextInt();
		int sum = 0;
		for (int i = 2; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (i + j == n && primes.contains(i) && primes.contains(j)) {
					sum++;
				}
			}
		}
		System.out.println(sum);
	}

}