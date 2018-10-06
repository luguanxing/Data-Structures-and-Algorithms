import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int s = in.nextInt();
		int l = in.nextInt();
		int inCD = (l - 1) / (s + 1) == 0 ? 1 : (l - 1) / (s + 1);
		int CD = 0;
		if (inCD > n) {
			CD = 1;
			if (n % 13 == 0) {
				CD++;
			}
		} else {
			if (inCD % 13 == 0) {
				inCD--;
			}
			CD = n / inCD;
			if (n % inCD != 0) {
				CD++;
			}
		}
		System.out.println(CD);
	}

}
