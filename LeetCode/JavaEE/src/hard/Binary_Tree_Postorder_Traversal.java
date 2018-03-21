package hard;

import java.util.ArrayList;
import java.util.List;

import medium.Binary_Tree_Preorder_Traversal.TreeNode;

public class Binary_Tree_Postorder_Traversal {

	public class TreeNode {
	    int val;
	    TreeNode left;
	    TreeNode right;
	    TreeNode(int x) { val = x; }
	}
	
	class Solution {
		List<Integer> result = new ArrayList<>();
		
		public void postOrder(TreeNode root) {
			if (root == null) {
				return;
			}
			postOrder(root.left);
			postOrder(root.right);
			result.add(root.val);
		}
		
	    public List<Integer> postorderTraversal(TreeNode root) {
	    	postOrder(root);
			return result;
	    }
	}
	
}
