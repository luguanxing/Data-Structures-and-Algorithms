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
	
}
