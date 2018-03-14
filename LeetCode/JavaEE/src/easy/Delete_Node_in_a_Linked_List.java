package easy;

public class Delete_Node_in_a_Linked_List {

	public class ListNode {
		int val;
		ListNode next;
		ListNode(int x) {
			val = x;
		}
	}

	class Solution {
		//将下个节点复制到当前，再删除下个节点
		public void deleteNode(ListNode node) {
			if (node == null) {
				return;
			}
			if (node.next == null) {
				node = null;
				return;
			}
			node.val = node.next.val;
			node.next = node.next.next;
		}
	}
	
	public static void main(String[] args) {
		
	}
	
}
