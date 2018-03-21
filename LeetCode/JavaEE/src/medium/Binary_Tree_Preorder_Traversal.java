package medium;

import java.util.ArrayList;
import java.util.List;

public class Binary_Tree_Preorder_Traversal {

	public class TreeNode {
	    int val;
	    TreeNode left;
	    TreeNode right;
	    TreeNode(int x) { val = x; }
	}
	
	class Solution {
		List<Integer> result = new ArrayList<>();
		
		public void preOrder(TreeNode root) {
			if (root == null) {
				return;
			}
			result.add(root.val);
			preOrder(root.left);
			preOrder(root.right);
		}
		
	    public List<Integer> preorderTraversal(TreeNode root) {
	    	preOrder(root);
			return result;
	    }
	}
	
}
