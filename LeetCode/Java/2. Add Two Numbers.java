import my.ListNode;

public class Solution {
	public static void main(String[] args) {
		ListNode nodes[] = new ListNode[4];
		nodes[0] = new ListNode(9);
		nodes[2] = new ListNode(3);
		nodes[3] = new ListNode(5);
		nodes[0].next = nodes[1];
		nodes[2].next = nodes[3];
		Solution solution = new Solution();
		solution.addTwoNumbers(nodes[0], nodes[2]);
	}
/*
 * 	V1.0Ô­°æ
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		int a1[] = new int[1000];
		int a2[] = new int[1000];
		int ct1, ct2, ct;
		for (ct1 = 0; l1 != null; ct1++) {
			a1[ct1] = l1.val;
			l1 = l1.next;
		}
		for (ct2 = 0; l2 != null; ct2++) {
			a2[ct2] = l2.val;
			l2 = l2.next;
		}
		ct = ct1 < ct2 ? ct2 : ct1;
		for (int i = 0; i < ct; i++) {
			a2[i] += a1[i];
			if (a2[i] >= 10) {
				a2[i+1] += (a2[i] / 10);
				a2[i] = a2[i] % 10;
			}
		}
		if (a2[ct] != 0)
			ct++;
		ListNode head = null;
		ListNode old = null;
		ListNode next = null;
		old = new ListNode(a2[0]);
		head = old;
		for (int i = 1; i < ct; i++) {
			next = new ListNode(a2[i]);
			old.next = next;
			old = next;
		}
		return head;
	}
*/
	
	//V2.0ÓÅ»¯°æ
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		ListNode head = new ListNode(0);
		ListNode old = null;
		ListNode next = null;
		old = next = head;
		int carry = 0;
		while (l1 != null || l2 != null) {
			int x = (l1 == null) ? 0 : l1.val;
			int y = (l2 == null) ? 0 : l2.val;
			int result = x + y + carry;
			carry = result / 10;
			result = result % 10;
			next = new ListNode(result);
			old.next = next;
			old = next;
			if (l1 != null) l1 = l1.next;
			if (l2 != null) l2 = l2.next;			
		}
		if (carry > 0) {
			next = new ListNode(carry);
			old.next = next;
			old = next;
		}
		return head.next;
	}
	
}
