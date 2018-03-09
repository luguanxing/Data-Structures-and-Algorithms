package easy;

public class Path_Sum {

	public class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;
		TreeNode(int x) { val = x; }
	}
	
	class Solution {
		int curSum = 0;
		//叶节点即左子节点null右节点null
	    public boolean hasPathSum(TreeNode root, int sum) {
	        if (root == null) {
	        	return false;
	        } else {
	        	if (curSum + root.val == sum && root.left == null && root.right == null) {
	        		return true;
	        	} else {
	        		curSum += root.val;
	        		boolean result1 = hasPathSum(root.left, sum);
	        		boolean result2 = hasPathSum(root.right, sum);
	        		curSum -= root.val;
	        		return result1 || result2;
				}
	        }
	    }
	}
	
	public static void main(String[] args) {
		Path_Sum main = new Path_Sum();
		TreeNode root = main.new TreeNode(1);
		TreeNode node = main.new TreeNode(2);
		root.left = node;
		System.out.println(main.new Solution().hasPathSum(root, 1));
	}
	
}
