package easy;

public class Invert_Binary_Tree {

	public class TreeNode {
	    int val;
	    TreeNode left;
	    TreeNode right;
	    TreeNode(int x) { val = x; }
	}
	
	class Solution {
		public void invert(TreeNode root) {
			if (root == null) {
	        	return;
	        }
			TreeNode temp = root.left;
			root.left = root.right;
			root.right = temp;
			invert(root.left);
			invert(root.right);
		}
		
	    public TreeNode invertTree(TreeNode root) {
	        if (root == null) {
	        	return null;
	        }
	        invert(root);
	        return root;
	    }
	}
	
}
