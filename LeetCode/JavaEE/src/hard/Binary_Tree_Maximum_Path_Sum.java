package hard;

public class Binary_Tree_Maximum_Path_Sum {

	public class TreeNode {
	    int val;
	    TreeNode left;
	    TreeNode right;
	    TreeNode(int x) { val = x; }
	}
	
	class Solution {
		public int max = Integer.MIN_VALUE;
		
	    public int maxPathSum(TreeNode root) {
	    	getMaxSumAndRecord(root);
	    	return max;
	    }
	    
    	// 计算当前节点下的最大和
	    public int getMaxSumAndRecord(TreeNode root) {
	    	if (root == null) {
	    		return 0;
	    	}
	    	// 需要向下递归计算当左右节点下的最大和(注意为去掉负数)，顺便记录经过当前节点时是否为最大(最大路径必在某节点分叉)
	    	int leftMax = Math.max(0, getMaxSumAndRecord(root.left));
	    	int rightMax = Math.max(0, getMaxSumAndRecord(root.right));
	    	max = Math.max(max, leftMax + rightMax + root.val);
	    	// 返回当前节点下的最大和(注意为去掉负数)
	    	return root.val + Math.max(0, Math.max(leftMax, rightMax));
	    }
	}
	
	public static void main(String[] args) {
		Binary_Tree_Maximum_Path_Sum main = new Binary_Tree_Maximum_Path_Sum();
		TreeNode root = main.new TreeNode(2);
		TreeNode l = main.new TreeNode(-1);
		TreeNode r = main.new TreeNode(-2);
		root.left = l;
		root.right = r;
//		TreeNode root = main.new TreeNode(-10);
//		TreeNode l = main.new TreeNode(9);
//		TreeNode r = main.new TreeNode(20);
//		TreeNode rl = main.new TreeNode(15);
//		TreeNode rr = main.new TreeNode(7);
//		root.left = l;
//		root.right = r;
//		r.left = rl;
//		r.right = rr;
		System.out.println(main.new Solution().maxPathSum(root));
	}
	
}
