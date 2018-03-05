package medium;

import java.util.ArrayList;
import java.util.List;

import medium.Binary_Tree_Inorder_Traversal.TreeNode;

public class Validate_Binary_Search_Tree {

	public class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;
		TreeNode(int x) { val = x; }
	}
	
	class Solution {
		public void addRootValToList(TreeNode root, List<Integer> list) {
			//按中序遍历取出值放入数组
			if (root.left != null)
				addRootValToList(root.left, list);
			list.add(root.val);
			if (root.right != null)
				addRootValToList(root.right, list);
		}
		
	    public boolean isValidBST(TreeNode root) {
	        if (root == null)
	        	return true;
	        List<Integer> list = new ArrayList<>();
	        //判断中序数组是否递增
	        addRootValToList(root, list);
	        if (list.size() == 1)
	        	return true;
	        for (int i = 1; i < list.size(); i++) {
	        	if (list.get(i-1) >= list.get(i))
	        		return false;
	        }
	    	return true;
	    }
	}
	
	public static void main(String[] args) {
		Validate_Binary_Search_Tree main = new Validate_Binary_Search_Tree();
		
		TreeNode root = main.new TreeNode(4);
		TreeNode left = main.new TreeNode(2);
		TreeNode right = main.new TreeNode(6);
		TreeNode leftleft = main.new TreeNode(0);
		TreeNode leftright = main.new TreeNode(3);
		TreeNode rightleft = main.new TreeNode(5);
		TreeNode rightright = main.new TreeNode(10);
		
//		TreeNode root = main.new TreeNode(10);
//		TreeNode left = main.new TreeNode(5);
//		TreeNode right = main.new TreeNode(15);
//		TreeNode leftleft = null;
//		TreeNode leftright = null;
//		TreeNode rightleft = main.new TreeNode(6);
//		TreeNode rightright = main.new TreeNode(20);
		
		root.left = left;
		root.right = right;
		left.left = leftleft;
		left.right = leftright;
		right.left = rightleft;
		right.right = rightright;
		
		System.out.println(main.new Solution().isValidBST(root));
	}

}
