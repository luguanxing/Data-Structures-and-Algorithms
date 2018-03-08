package easy;

import java.util.HashSet;
import java.util.Set;

public class Linked_List_Cycle {

	class ListNode {
		int val;
		ListNode next;
		ListNode(int x) {
			val = x;
			next = null;
		}
	}

	public class Solution {
		
		//暴力修改判断
		public boolean hasCycle(ListNode head) {
			if (head == null)
				return false;
			ListNode p = head;
			while (p != null) {
				if (p.val == Integer.MAX_VALUE) {
					return true;
				}
				p.val = Integer.MAX_VALUE;
				p = p.next;
			}
			return false;
		}
		
		//使用set，占用空间
		public boolean hasCycle_set(ListNode head) {
			if (head == null)
				return false;
			ListNode p = head;
			Set<ListNode> set = new HashSet();
			while (p != null) {
				if (set.contains(p)) {
					return true;
				}
				set.add(p);
				p = p.next;
			}
			return false;
		}
	}
	
	
}
