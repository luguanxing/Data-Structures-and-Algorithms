package medium;

import java.util.ArrayList;
import java.util.List;

import easy.Same_Tree.TreeNode;

public class Binary_Tree_Inorder_Traversal {

	public class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;
		TreeNode(int x) { val = x; }
	}
	

	class Solution {
		public void addToList(TreeNode root, List<Integer> list) {
			//注意边界条件
			if (root == null)
				return;
			//中序遍历
			if (root.left != null) {
				addToList(root.left, list);
			}
			list.add(root.val);
			if (root.right != null) {
				addToList(root.right, list);
			}
		}
		
	    public List<Integer> inorderTraversal(TreeNode root) {
	    	List<Integer> list = new ArrayList<>();
	        addToList(root, list);
	    	return list;
	    }
	}
	
	public static void main(String[] args) {
		
	}
	
}
