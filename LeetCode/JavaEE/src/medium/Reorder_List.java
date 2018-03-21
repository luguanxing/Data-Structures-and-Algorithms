package medium;

import java.util.ArrayList;
import java.util.List;

public class Reorder_List {

	public class ListNode {
		int val;
		ListNode next;
		ListNode(int x) {
			val = x;
		}
		@Override
		public String toString() {
			return"[" + val + "] " + next;
		}
	}

	class Solution {
		public void reorderList(ListNode head) {
			if (head == null) {
				return;
			}
			List<ListNode> list = new ArrayList();
			while (head != null) {
				list.add(head);
				head = head.next;
			}
			int left = 0;
			int right = list.size() - 1;
			while (left < right) {
				list.get(left).next = list.get(right);
				if (left + 1 == right) {
					break;
				} else {
					list.get(right--).next = list.get(++left);
				}
			}
			if (list.size() % 2 == 0) {
				list.get(right).next = null;
			} else {
				list.get(left).next = null;
			}
		}
	}

	public static void main(String[] args) {
		Reorder_List main = new Reorder_List();
		ListNode listNode1 = main.new ListNode(1);
		ListNode listNode2 = main.new ListNode(2);
		ListNode listNode3 = main.new ListNode(3);
		ListNode listNode4 = main.new ListNode(4);
		listNode1.next = listNode2;
		listNode2.next = listNode3;
		listNode3.next = listNode4;
		System.out.println(listNode1);
		main.new Solution().reorderList(null);
		System.out.println(listNode1);
	}
	
}
