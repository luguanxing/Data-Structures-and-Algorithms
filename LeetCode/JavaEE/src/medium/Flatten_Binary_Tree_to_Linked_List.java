package medium;

import java.util.ArrayList;
import java.util.List;

public class Flatten_Binary_Tree_to_Linked_List {

	public class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;
		TreeNode(int x) {
			val = x;
		}
	}

	class Solution {
		
		List<TreeNode> list = new ArrayList<>();
		
		public void preOrder(TreeNode root) {
			if (root == null) {
				return;
			}
			list.add(root);
			preOrder(root.left);
			preOrder(root.right);
		}
		
		public void flatten(TreeNode root) {
			if (root == null) {
				return;
			}
			preOrder(root);
			for (int i = 0; i < list.size() - 1; i++) {
				TreeNode node = list.get(i);
				node.left = null;
				node.right = list.get(i + 1);
			}
			list.get(list.size() - 1).left = null;
			list.get(list.size() - 1).right = null;
		}
	}

}
