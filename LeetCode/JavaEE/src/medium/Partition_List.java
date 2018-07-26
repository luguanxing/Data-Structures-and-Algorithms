package medium;

import java.util.ArrayList;
import java.util.List;

public class Partition_List {

	public class ListNode {
		int val;
		ListNode next;

		ListNode(int x) {
			val = x;
		}
	}

	class Solution {
		public ListNode partition(ListNode head, int x) {
			if (head == null) {
				return null;
			}
			// 更好的方法不是用list而是用两个链表分别连接比x大和小的数最后再相连
			List<ListNode> list = new ArrayList<>();
			ListNode p = head;
			while (p != null) {
				if (p.val < x) {
					list.add(p);
				}
				p = p.next;
			}
			p = head;
			while (p != null) {
				if (p.val >= x) {
					list.add(p);
				}
				p = p.next;
			}
			for (int i = 0; i < list.size() - 1; i++) {
				list.get(i).next = list.get(i + 1);
			}
			list.get(list.size() - 1).next = null;
			return list.get(0);
		}
	}

}
