package medium;

public class Sum_Root_to_Leaf_Numbers {

	public class TreeNode {
	    int val;
	    TreeNode left;
	    TreeNode right;
	    TreeNode(int x) { val = x; }
	}
	
	class Solution {
		int sum = 0;
		
		// 传递的参数可用字符串，但用10*curSum更快
		public void preOrderAndAdd(TreeNode root, int curSum) {
			if (root == null) {
				return;
			}
			if (root.left == null && root.right == null) {
				sum += curSum * 10 + root.val;
				return;
			}
			preOrderAndAdd(root.left, curSum * 10 + root.val);
			preOrderAndAdd(root.right, curSum * 10 + root.val);
		}
		
	    public int sumNumbers(TreeNode root) {
	        preOrderAndAdd(root, 0);
	        return sum;
	    }
	}
	
	public static void main(String[] args) {
		Sum_Root_to_Leaf_Numbers main = new Sum_Root_to_Leaf_Numbers();
		TreeNode root = main.new TreeNode(1);
		TreeNode left = main.new TreeNode(2);
		TreeNode right = main.new TreeNode(3);
		root.left = left;
		root.right = right;
		System.out.println(main.new Solution().sumNumbers(root));
	}

}
