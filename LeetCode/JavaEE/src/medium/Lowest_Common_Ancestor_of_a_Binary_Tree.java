package medium;

import java.util.ArrayList;
import java.util.List;

public class Lowest_Common_Ancestor_of_a_Binary_Tree {

	public class TreeNode {
	    int val;
	    TreeNode left;
	    TreeNode right;
	    TreeNode(int x) { val = x; }
	}
	
	class Solution {

		List<TreeNode> rootPath1 = null;
		List<TreeNode> rootPath2 = null;

		public void preOrderFind(TreeNode curNode, TreeNode target, List<TreeNode> curPath, boolean isPath1) {
			if (curNode == null) {
				return;
			}
			if (curNode == target) {
				curPath.add(curNode);
				if (isPath1) {
					rootPath1 = new ArrayList<>(curPath);
				} else {
					rootPath2 = new ArrayList<>(curPath);
				}
				return;
			}
			curPath.add(curNode);
			preOrderFind(curNode.left, target, curPath, isPath1);
			preOrderFind(curNode.right, target, curPath, isPath1);
			curPath.remove(curNode);
		}

		public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
			if (root == null) {
				return null;
			}
			preOrderFind(root, p, new ArrayList(), true);
			preOrderFind(root, q, new ArrayList(), false);
			int minLen = Math.min(rootPath1.size(), rootPath2.size());
			TreeNode result = null;
			for (int i = 0; i < minLen; i++) {
				if (rootPath1.get(i) == rootPath2.get(i)) {
					result = rootPath1.get(i);
					continue;
				} else {
					break;
				}
			}
			return result;
		}
	}
	
	class Solution_Better {
	    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
	        
	    	// 遇到某个节点则返回
	        if(root == null || root == p || root == q){
	            return root;
	        }
	        
	        // 向下递归，判断公共节点与左右子树的关系
	        TreeNode left = lowestCommonAncestor(root.left, p, q);
	        TreeNode right = lowestCommonAncestor(root.right, p, q);
	        
	        // 如果两边都有则本节点为分叉，否则在某子树，向下递归
	        if(left != null && right != null){
	            return root;
	        }else if (left != null){
	            return lowestCommonAncestor(left, p, q);
	        }else {
	            return lowestCommonAncestor(right, p, q);
	        }
	    }
	}
	
}
