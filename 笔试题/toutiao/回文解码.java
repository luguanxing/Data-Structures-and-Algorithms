import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		StringBuilder sb = new StringBuilder(in.next());
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			int start = in.nextInt();
			int len = in.nextInt();
			sb.insert(start + len, new StringBuilder(sb.substring(start, start + len)).reverse());
		}
		System.out.println(sb.toString());
	}

}
