package medium;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Binary_Tree_Inorder_Traversal_No_Recursive {

	public class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;
		TreeNode(int x) {
			val = x;
		}
		@Override
		public String toString() {
			return "" + val;
		}
	}

	class Solution {
		public List<Integer> inorderTraversal(TreeNode root) {
			List<Integer> result = new ArrayList<>();
			Stack<TreeNode> stack = new Stack<>();
			if (root == null) {
				return result;
			}
			stack.push(root);
			TreeNode curNode = stack.peek();
			// curNode是当前要处理的节点(不能指回栈中保存过的)，优先往左探索，无法再往左才从栈中取一个输出并往右一步
			while (!stack.isEmpty()) {
				if (curNode != null) {
					stack.push(curNode.left);
					curNode = curNode.left;
				} else {
					TreeNode lastNode = stack.pop();
					if (lastNode != null) {
						// 注意中序遍历是左中右，所以在向右跨步的时候才输出
						result.add(lastNode.val);
						stack.push(lastNode.right);
						curNode = lastNode.right;
					}
				}
			}
			return result;
		}
	}

	public static void main(String[] args) {
		Binary_Tree_Inorder_Traversal_No_Recursive main = new Binary_Tree_Inorder_Traversal_No_Recursive();
		TreeNode root = main.new TreeNode(1);
		TreeNode node_l = main.new TreeNode(2);
		TreeNode node_ll = main.new TreeNode(3);
		root.left = node_l;
		node_l.left = node_ll;
		System.out.println(main.new Solution().inorderTraversal(root));
	}
}
