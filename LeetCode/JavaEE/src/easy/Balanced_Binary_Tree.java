package easy;

public class Balanced_Binary_Tree {

	public class TreeNode {
	    int val;
	    TreeNode left;
	    TreeNode right;
	    TreeNode(int x) { val = x; }
	    @Override
	    public String toString() {
	    	return val + "";
	    }
	}
	
	class Solution {
		private int max = 0;
		
		public void testDeep(TreeNode root, int curDeep) {
			if (root == null) {
				return;
			}
			if (curDeep > max) {
				max = curDeep;
			}
			testDeep(root.left, curDeep + 1);
			testDeep(root.right, curDeep + 1);
		}
		
		public int getDeepLength(TreeNode root) {
			if (root == null) {
				return 0;
			}
			testDeep(root, 1);
			int result = max;
			max = 0;
			return result;
		}
		
	    public boolean isBalanced(TreeNode root) {
	        if (root == null) {
	        	return true;
	        }
	        int leftDeepLength = getDeepLength(root.left);
	        int rightDeepLength = getDeepLength(root.right);
	        int diff = leftDeepLength - rightDeepLength;
	        if (diff < -1 || diff > 1) {
	        	return false;
	        } else {
	        	return isBalanced(root.left) && isBalanced(root.right);
	        }
	    }
	}
	
	public static void main(String[] args) {
		Balanced_Binary_Tree main = new Balanced_Binary_Tree();
		TreeNode root = main.new TreeNode(3);
		TreeNode nodel = main.new TreeNode(9);
		TreeNode noder = main.new TreeNode(20);
		TreeNode noderl = main.new TreeNode(15);
		TreeNode noderr = main.new TreeNode(7);
		root.left = nodel;
		root.right = noder;
		noder.left = noderl;
		noder.right = noderr;
		System.out.println(main.new Solution().isBalanced(root));
	}
	
}
