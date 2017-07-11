import java.util.Set;
import java.util.Stack;

import my.ListNode;

public class Solution {
	public static void main(String[] args) {
		int[] a1 = {1, 3};
		int[] a2 = {2};
		int[] b1 = {1, 2, 3};
		int[] b2 = {4, 5, 6};
		Solution so = new Solution();
		System.out.println(so.findMedianSortedArrays(a1, a2));
		System.out.println(so.findMedianSortedArrays(b1, b2));
	}
	
	//V2.0归并比较两点版
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len = nums1.length + nums2.length;
        double old = 0;;
        double next = 0;
        int ct1 = 0;
        int ct2 = 0;
        while (true) {
        	old = next;
			if (ct1 == nums1.length) {
				next = nums2[ct2++];
			} else if (ct2 == nums2.length) {
				next = nums1[ct1++];
			} else {
				if (nums1[ct1] < nums2[ct2]) {
					next = nums1[ct1++];
				} else {
					next = nums2[ct2++];
				}
			}
			if (ct1 + ct2 - 1 == len/2) {
		        if (len % 2 == 0) {
		        	return (old+next)/2;
		        } else {
		        	return next;
		        }
			}
		}
    }
	
/*
 * 	V1.0归并比较新建数组版
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len = nums1.length + nums2.length;
        double nums[] = new double[len];
        int ct1 = 0;
        int ct2 = 0;
        while (ct1 + ct2 < len) {
			if (ct1 == nums1.length) {
				nums[ct1 + ct2] = nums2[ct2++];
			} else if (ct2 == nums2.length) {
				nums[ct1 + ct2] = nums1[ct1++];
			} else {
				if (nums1[ct1] < nums2[ct2]) {
					nums[ct1 + ct2] = nums1[ct1++];
				} else {
					nums[ct1 + ct2] = nums2[ct2++];
				}
			}
		}
        if (len % 2 == 0) {
        	return (nums[len/2] + nums[len/2-1])/2;
        } else {
        	return nums[len/2];
        }
    }
*/
}
