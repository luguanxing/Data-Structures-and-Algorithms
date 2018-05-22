package easy;

public class Minimum_Depth_of_Binary_Tree {

	public class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;

		TreeNode(int x) {
			val = x;
		}
	}

	class Solution {

		int min = Integer.MAX_VALUE;

		public void preOrder(TreeNode root, int depth) {
			if (root == null) {
				return;
			} else {
				if (root.left == null && root.right == null) {
					min = Math.min(min, depth);
				} 
				preOrder(root.left, depth + 1);
				preOrder(root.right, depth + 1);
			}
		}

		public int minDepth(TreeNode root) {
			if (root == null) {
				return 0;
			}
			preOrder(root, 0);
			return min + 1;
		}
	}
	
	public static void main(String[] args) {
		Minimum_Depth_of_Binary_Tree main = new Minimum_Depth_of_Binary_Tree();
		TreeNode root = main.new TreeNode(3);
		TreeNode l = main.new TreeNode(9);
		TreeNode r = main.new TreeNode(20);
		TreeNode rl = main.new TreeNode(15);
		TreeNode rr = main.new TreeNode(7);
		root.left = l;
		root.right = r;
		r.left = rl;
		r.right = rr;
		System.out.println(main.new Solution().minDepth(root));
	}

}
