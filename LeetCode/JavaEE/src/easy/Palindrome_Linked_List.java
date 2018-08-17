package easy;

import java.util.ArrayList;
import java.util.List;

public class Palindrome_Linked_List {

	public class ListNode {
		int val;
		ListNode next;
		ListNode(int x) {
			val = x;
		}
	}

	class Solution {
		public boolean isPalindrome(ListNode head) {
			// 不用List应该也可以，用一头一尾两个指针相向判断
			List<ListNode> list = new ArrayList<>();
			while (head != null) {
				list.add(head);
				head = head.next;
			}
			for (int i = 0; i < list.size() / 2; i++) {
				if (list.get(i).val != list.get(list.size() - 1 - i).val) {
					return false;
				}
			}
			return true;
		}
	}
	
	public static void main(String[] args) {
		Palindrome_Linked_List main = new Palindrome_Linked_List();
		ListNode node1 = main.new ListNode(1);
		ListNode node2 = main.new ListNode(1);
		node1.next = node2;
		System.out.println(main.new Solution().isPalindrome(node1));
	}

}
