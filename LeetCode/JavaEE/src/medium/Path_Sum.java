package medium;

public class Path_Sum {

	public class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;
		TreeNode(int x) {
			val = x;
		}
	}

	class Solution {
		public boolean check(TreeNode root, int sum, int curSum) {
			if (root == null) {
				return false;
			}
			if (sum == curSum + root.val && root.left == null && root.right == null) {
				return true;
			} else {
				return check(root.left, sum, curSum + root.val) || check(root.right, sum, curSum + root.val);
			}
		}
		
		public boolean hasPathSum(TreeNode root, int sum) {
			if (root == null) {
				return false;
			}
			return check(root, sum, 0);
		}
	}
	
	public static void main(String[] args) {
		Path_Sum main = new Path_Sum();
		TreeNode root = main.new TreeNode(1);
		TreeNode node = main.new TreeNode(2);
		root.left = node;
		int sum = 1;
		System.out.println(main.new Solution().hasPathSum(root, sum));
	}

}
