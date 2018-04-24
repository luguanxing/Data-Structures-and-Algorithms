package medium;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Copy_List_with_Random_Pointer {

	class RandomListNode {
		int label;
		RandomListNode next, random;

		RandomListNode(int x) {
			this.label = x;
		}

		@Override
		public String toString() {
			String out = "" + label;
			if (random != null) {
				out += "《" + random.label + "》";
			}
			if (next != null) {
				out += "->" + next;
			}
			return out;
		}
	}

	public class Solution {
		public RandomListNode copyRandomList(RandomListNode head) {
			if (head == null) {
				return null;
			}
			Map<RandomListNode, Integer> map = new HashMap();
			List<RandomListNode> oldLinkedList = new ArrayList<>();
			List<RandomListNode> newLinkedList = new ArrayList<>();
			Integer index = 0;
			// 将旧链表位置有序保存并创建新链表
			do {
				map.put(head, index++);
				oldLinkedList.add(head);
				newLinkedList.add(new RandomListNode(head.label));
				head = head.next;
			} while (head != null);
			// 连接新链表的next,并将random在旧链表所在位置到对应的新链表
			for (int i = 0; i < newLinkedList.size() - 1; i++) {
				newLinkedList.get(i).next = newLinkedList.get(i + 1);
				RandomListNode oldNodeRandom = oldLinkedList.get(i).random;
				if (oldNodeRandom != null) {
					newLinkedList.get(i).random = newLinkedList.get(map.get(oldNodeRandom));
				}
			}
			// 别忘了最后一个的random
			RandomListNode oldNodeRandom = oldLinkedList.get(newLinkedList.size() - 1).random;
			if (oldNodeRandom != null) {
				newLinkedList.get(newLinkedList.size() - 1).random = newLinkedList.get(map.get(oldNodeRandom));
			}
			return newLinkedList.get(0);
		}
	}

	public static void main(String[] args) {
		Copy_List_with_Random_Pointer main = new Copy_List_with_Random_Pointer();
		RandomListNode head = main.new RandomListNode(1);
		RandomListNode node1 = main.new RandomListNode(2);
		RandomListNode node2 = main.new RandomListNode(3);
		head.next = node1;
		head.random = node2;
		node1.next = node2;
		node1.random = node2;
		RandomListNode newHead = main.new Solution().copyRandomList(head);
		System.out.println(head);
		System.out.println(newHead);
	}

}
