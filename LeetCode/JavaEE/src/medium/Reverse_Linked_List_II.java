package medium;

import java.util.ArrayList;
import java.util.List;

import easy.Reverse_Linked_List.ListNode;


public class Reverse_Linked_List_II {

	public class ListNode {
		int val;
		ListNode next;
		ListNode(int x) { val = x; }
		@Override
		public String toString() {
			return "[" + val + "]";
		}
	}
	
	class Solution {
		//用List替换，颠倒的结点List用另一个存储，替换List顺序后重新链接
		public ListNode reverseBetween(ListNode head, int m, int n) {
	        if (head == null) {
	        	return null;
	        }
	        if (m == n) {
	        	return head;
	        }
	        List<ListNode> list = new ArrayList();
	        List<ListNode> revList = new ArrayList();
	        ListNode p = head;
	        while (p != null) {
	        	list.add(p);
	        	p = p.next;
	        }
	        for (int i = 1; i < list.size(); i++) {
	        	list.get(i).next = list.get(i-1);
	        }
	        for (int i = m-1; i < n; i++) {
	        	revList.add(list.get(i));
	        }
	        int count = 1;
	        for (int i = m-1; i < n; i++) {
	        	list.set(i, revList.get(revList.size() - (count++)));
	        }
	        for (int i = 0; i < list.size()-1; i++) {
	        	list.get(i).next = list.get(i+1);
	        }
	        list.get(list.size()-1).next = null;
			return list.get(0);
		}
	}
	
	public static void main(String[] args) {
		Reverse_Linked_List_II main = new Reverse_Linked_List_II();
		ListNode node1 = main.new ListNode(1);
		ListNode node2 = main.new ListNode(2);
		ListNode node3 = main.new ListNode(3);
		ListNode node4 = main.new ListNode(4);
		ListNode node5 = main.new ListNode(5);
		node1.next = node2;
		node2.next = node3;
		node3.next = node4;
		node4.next = node5;
		ListNode result = main.new Solution().reverseBetween(node1, 1, 2);
		System.out.println(result);
	}
	
	
}
