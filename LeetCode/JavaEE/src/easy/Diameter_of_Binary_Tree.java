package easy;

public class Diameter_of_Binary_Tree {

	public class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;
		TreeNode(int x) {
			val = x;
		}
	}

	class Solution {
		public int max = 0;
		
		public int diameterOfBinaryTree(TreeNode root) {
			getMaxHeightAndRecordSum(root);
			return max;
		}

		// 因为计算最深节点时必把下面所有节点递归遍历了，所以把左右和一起计算能避免重复计算，从而达到优化效果
		public int getMaxHeightAndRecordSum(TreeNode root) {
			if (root == null) {
				return 0;
			}
			int leftMax = getMaxHeightAndRecordSum(root.left);
			int rightMax = getMaxHeightAndRecordSum(root.right);
			max = Math.max(max, leftMax + rightMax);
			return Math.max(leftMax, rightMax) + 1;
		}
	}
	
	class Solution_ {
		// 存储最大的结果
		public int max = 0;
		
		public int diameterOfBinaryTree(TreeNode root) {
			if (root == null) {
				return 0;
			}
			// 计算当前节点左最深加右最深的和
			max = Math.max(max, getMaxHeight(root.left) + getMaxHeight(root.right));
			// 向下继续检查(产生重复计算，未优化)
			diameterOfBinaryTree(root.left);
			diameterOfBinaryTree(root.right);
			return max;
		}

		// 递归获取节点最深值(产生重复计算，未优化)
		public int getMaxHeight(TreeNode root) {
			if (root == null) {
				return 0;
			}
			return Math.max(getMaxHeight(root.left) + 1, getMaxHeight(root.right) + 1);
		}
	}
	
	public static void main(String[] args) {
		Diameter_of_Binary_Tree main = new Diameter_of_Binary_Tree();
		TreeNode root = main.new TreeNode(1);
		TreeNode l = new Diameter_of_Binary_Tree().new TreeNode(2);
		TreeNode r = new Diameter_of_Binary_Tree().new TreeNode(3);
		TreeNode ll = new Diameter_of_Binary_Tree().new TreeNode(4);
		TreeNode lr = new Diameter_of_Binary_Tree().new TreeNode(5);
		root.left = l;
		root.right = r;
		l.left = ll;
		l.right = lr;
		System.out.println(main.new Solution().diameterOfBinaryTree(root));
	}

}
