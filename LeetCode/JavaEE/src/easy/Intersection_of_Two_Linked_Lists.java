package easy;

public class Intersection_of_Two_Linked_Lists {

	public class ListNode {
		int val;
		ListNode next;
		ListNode(int x) {
			val = x;
			next = null;
		}
	}

	public class Solution {
		public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
			// 空链表则返回
			if (headA == null || headB == null) {
				return null;
			}
			// 先计算出长度，让长的先移动一段，再比较最后剩下的部分
			int lenA = 1;
			int lenB = 1;
			ListNode pointA = headA;
			while (pointA.next != null) {
				pointA = pointA.next;
				lenA++;
			}
			ListNode pointB = headB;
			while (pointB.next != null) {
				pointB = pointB.next;
				lenB++;
			}
			pointA = headA;
			pointB = headB;
			int step = 0;
			if (lenA > lenB) {
				step = lenA - lenB;
				while (step > 0) {
					step--;
					pointA = pointA.next;
				}
			} else {
				step = lenB - lenA;
				while (step > 0) {
					step--;
					pointB = pointB.next;
				}
			}
			while (pointA != null && pointB != null) {
				if (pointA == pointB) {
					return pointA;
				}
				pointA = pointA.next;
				pointB = pointB.next;
			}
			return null;
		}
	}

}
