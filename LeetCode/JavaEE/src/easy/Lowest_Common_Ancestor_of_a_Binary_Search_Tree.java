package easy;

import java.util.ArrayList;
import java.util.List;

public class Lowest_Common_Ancestor_of_a_Binary_Search_Tree {

	public class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;

		TreeNode(int x) {
			val = x;
		}

		@Override
		public String toString() {
			return val + "";
		}
	}

	class Solution {
		public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
			if (root == null) {
				return null;
			}
			// 它们为直系并且遇到其中一个直接返回
			if (root == p || root == q) {
				return root;
			}
			// 利用二叉搜索树条件，若比p和q都小，说明可以向右子树继续找
			if (root.val < p.val && root.val < q.val) {
				return lowestCommonAncestor(root.right, p, q);
			}
			// 利用二叉搜索树条件，若比p和q都小，说明可以向左子树继续找
			if (root.val > p.val && root.val > q.val) {
				return lowestCommonAncestor(root.left, p, q);
			}
			// 利用二叉搜索树条件，若找到某个分叉点(大小在p和q之间)即为所求
			return root;
		}
	}

	class Solution_NoBST {

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

	public static void main(String[] args) {
		Lowest_Common_Ancestor_of_a_Binary_Search_Tree main = new Lowest_Common_Ancestor_of_a_Binary_Search_Tree();
		TreeNode root = main.new TreeNode(1);
		TreeNode l = main.new TreeNode(0);
		TreeNode r = main.new TreeNode(3);
		root.left = l;
		root.right = r;
		System.out.println(main.new Solution().lowestCommonAncestor(root, l, r));
	}

}
