package medium;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Binary_Tree_Zigzag_Level_Order_Traversal {

	public class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;

		TreeNode(int x) {
			val = x;
		}
	}

	class Solution {
		int deepest = 0;

		List<List<Integer>> result = new ArrayList<>();

		private void preOrder(TreeNode root, int curDeep) {
			if (root == null) {
				return;
			}
			if (curDeep >= deepest) {
				List<Integer> list = new ArrayList<>();
				list.add(root.val);
				result.add(list);
				deepest++;
			} else {
				List<Integer> list = result.get(curDeep);
				list.add(root.val);
			}
			preOrder(root.left, curDeep + 1);
			preOrder(root.right, curDeep + 1);
		}

		public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
			preOrder(root, 0);
			for (int i = 0; i < result.size(); i++) {
				if (i % 2 == 1) {
					Collections.reverse(result.get(i));
				}
			}
			return result;
		}
	}
	
	public static void main(String[] args) {
		Binary_Tree_Zigzag_Level_Order_Traversal main = new Binary_Tree_Zigzag_Level_Order_Traversal();
		TreeNode root = main.new TreeNode(3);
		TreeNode l = main.new TreeNode(9);
		TreeNode r = main.new TreeNode(20);
		TreeNode rl = main.new TreeNode(15);
		TreeNode rr = main.new TreeNode(7);
		root.left = l;
		root.right = r;
		r.left = rl;
		r.right = rr;
		main.new Solution().zigzagLevelOrder(root);
	}

}
