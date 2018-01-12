package easy;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

public class Intersection_of_Two_Arrays {

    public int[] intersection(int[] nums1, int[] nums2) {
    	Set<Integer> set1 = new HashSet();
    	Set<Integer> set2 = new HashSet();
    	Set<Integer> set = new HashSet();
    	for (Integer i : nums1)
			set1.add(i);
    	for (Integer i : nums2)
			set2.add(i);
    	set.addAll(set1);
    	set.retainAll(set2);
    	int[] result = new int[set.size()];
    	int ct = 0;
    	for (int num : set) {
			result[ct++] = num;
		}
    	return result;
    }
	
	public static void main(String[] args) {
		int[] nums1 = {1, 2, 2, 1};
		int[] nums2 = {2, 2};
		System.out.println(Arrays.toString(new Intersection_of_Two_Arrays().intersection(nums1, nums2)));
	}

}
