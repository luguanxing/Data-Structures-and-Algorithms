package easy;

public class Climbing_Stairs {

    int climbStairs(int n) {
    	if (n == 0)
    		return 0;
        int arr[] = new int[n+1];
        arr[0] = 1;
        arr[1] = 2;
        for (int i = 2; i < n; i++)
        	arr[i] = arr[i-1] + arr[i-2];
    	return arr[n-1];
    }
	
	public static void main(String[] args) {
		System.out.println(new Climbing_Stairs().climbStairs(4));
	}

}
