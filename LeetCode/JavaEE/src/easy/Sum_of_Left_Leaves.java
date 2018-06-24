package easy;

public class Sum_of_Left_Leaves {

	public class TreeNode {
	    int val;
	    TreeNode left;
	    TreeNode right;
	    TreeNode(int x) { val = x; }
	    @Override
	    public String toString() {
	    	return "" + val;
	    }
	}
	
	class Solution {
		int sum = 0;
		
		public void preOreder(TreeNode root, boolean isLeft) {
	    	if (root == null) {
	    		return;
	    	}
	    	preOreder(root.left, true);
	    	if (isLeft) {
	    		if (root.left == null && root.right == null) {
	    			sum += root.val;
	    		}
	    	}
	    	preOreder(root.right, false);
		}
		
	    public int sumOfLeftLeaves(TreeNode root) {
	    	preOreder(root, false);
	        return sum;
	    }
	}
	
	public static void main(String[] args) {
		Sum_of_Left_Leaves main = new Sum_of_Left_Leaves();
		TreeNode root = main.new TreeNode(3);
		TreeNode l = main.new TreeNode(9);
		TreeNode r = main.new TreeNode(20);
		TreeNode rl = main.new TreeNode(15);
		TreeNode rr = main.new TreeNode(7);
		root.left = l;
		root.right = r;
		r.left = rl;
		r.right = rr;
		System.out.println(main.new Solution().sumOfLeftLeaves(root));
	}
	
}
