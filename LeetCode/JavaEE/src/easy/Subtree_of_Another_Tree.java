package easy;

public class Subtree_of_Another_Tree {

	public class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;

		TreeNode(int x) {
			val = x;
		}

		@Override
		public String toString() {
			return "" + val;
		}
	}

	class Solution {
		boolean result = false;

		// 先序遍历s，同时对每个节点逐个判断t
		public boolean isSubtree(TreeNode s, TreeNode t) {
			preOrder(s, t);
			return result;
		}

		// 先序遍历
		public void preOrder(TreeNode s, TreeNode t) {
			if (s != null) {
				result = result || isSameRoot(s, t);
				if (s.left != null) {
					preOrder(s.left, t);
				}
				if (s.right != null) {
					preOrder(s.right, t);
				}
			}
		}

		// 判断是否和当前节点相同
		public boolean isSameRoot(TreeNode s, TreeNode t) {
			if (s == null && t == null) {
				return true;
			}
			if (s != null && t != null && s.val == t.val) {
				return isSameRoot(s.left, t.left) && isSameRoot(s.right, t.right);
			}
			return false;
		}

	}

	public static void main(String[] args) {
		Subtree_of_Another_Tree main = new Subtree_of_Another_Tree();
		TreeNode root = main.new TreeNode(1);
		TreeNode node1 = main.new TreeNode(1);
		TreeNode node2 = main.new TreeNode(2);
		root.right = node1;
		node1.right = node2;
		TreeNode node = main.new TreeNode(1);
		TreeNode node_1 = main.new TreeNode(2);
		node.right = node_1;
		System.out.println(main.new Solution().isSubtree(root, node));
	}

}
