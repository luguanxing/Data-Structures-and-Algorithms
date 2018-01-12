package easy;
import java.util.Arrays;

public class Array_Partition_I {

	public static void main(String[] args) {
		int[] a = {1,4,3,2};
		System.out.println(arrayPairSum(a));;
	}
	
    public static int arrayPairSum(int[] nums) {
        Arrays.sort(nums);
        int sum = 0;
        for (int i = 0; i < nums.length; i+=2) {
        		sum += nums[i];
        }
    	return sum;
    }
}
