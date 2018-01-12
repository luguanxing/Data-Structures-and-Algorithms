package easy;
import java.awt.List;
import java.util.LinkedList;

public class Remove_Element {

	public static void main(String[] args) {
		int[] a = {2, 2, 3};
		System.out.println(removeElement(a, 2));
		for (int i : a) {
			System.out.print(i + " ");
		}
	}
	
    public static int removeElement(int[] nums, int val) {
    	int ct = 0;
    	for (int i = 0; i < nums.length; i++) {
    		if (nums[i] != val)
    			nums[ct++] = nums[i];
    	}
    	return ct;
    }
	
//    public static int removeElement(int[] nums, int val) {
//        int same = 0;
//        LinkedList list = new LinkedList();
//        for (int i = 0; i < nums.length; i++) {
//        	if (nums[i] == val) 
//        		same++;
//        	else
//        		list.add(nums[i]);
//		}
//        for (int i = 0; i < list.size(); i++)
//        	nums[i] = (int) list.get(i);
//    	return nums.length - same;
//    }
}
