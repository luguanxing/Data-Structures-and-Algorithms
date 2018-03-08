package medium;

import java.util.HashSet;
import java.util.Set;

public class Linked_List_Cycle_II {

	class ListNode {
		int val;
		ListNode next;
		ListNode(int x) {
			val = x;
			next = null;
		}
	}
	
	public class Solution {
	    public ListNode detectCycle(ListNode head) {
			if (head == null)
				return null;
			ListNode p = head;
			Set<ListNode> set = new HashSet();
			while (p != null) {
				if (set.contains(p)) {
					return p;
				}
				set.add(p);
				p = p.next;
			}
			return null;
	    }
	}
	
}
