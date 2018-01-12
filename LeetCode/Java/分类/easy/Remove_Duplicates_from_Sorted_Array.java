package easy;
import java.util.Arrays;
import java.util.Set;
import java.util.TreeSet;

public class Remove_Duplicates_from_Sorted_Array {

	public static void main(String[] args) {
		int[] a = {1};
		System.out.println(removeDuplicates(a));
	}
	
    public static int removeDuplicates(int[] nums) {
    	if (nums.length == 0)
    		return 0;
    	int sum = 1;	//��һ���϶������ظ�
    	for (int i = 1; i < nums.length; i++) {
    		if (nums[i] != nums[i-1])
    			nums[sum++] = nums[i];
    	}
    	return sum;
    }
    
//    public static int removeDuplicates(int[] nums) {
//        Set set = new TreeSet();
//        for (int i = 0; i < nums.length; i++)
//        	set.add(nums[i]);
//        int ct = 0;
//        for (Object object : set) {
//        	nums[ct++] = (int) object;
//		}
//    	return set.size();
//    }
    
}
