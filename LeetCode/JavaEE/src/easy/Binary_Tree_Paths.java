package easy;

import java.util.LinkedList;
import java.util.List;

public class Binary_Tree_Paths {

	public class TreeNode {
	    int val;
	    TreeNode left;
	    TreeNode right;
	    TreeNode(int x) { val = x; }
	    @Override
	    public String toString() {
	    	return val + "";
	    }
	}
	
	class Solution {
		
		List<String> allResult = new LinkedList<>();
		
		public void preOrder(TreeNode root, List<TreeNode> nodes) {
			// 空节点不处理
			if (root == null) {
				return;
			}
			// 到了叶子节点将已保存节点进行输出
			if (root.left == null && root.right == null) {
				String result = "";
				for (int i = 0; i < nodes.size(); i++) {
					result += nodes.get(i).val + "->";
				}
				result += root.val;
				allResult.add(result);
				return;
			}
			// 非叶节点则保存当前节点向下递归，注意回溯
			nodes.add(root);
			preOrder(root.left, nodes);
			preOrder(root.right, nodes);
			nodes.remove(root);
		}
		
	    public List<String> binaryTreePaths(TreeNode root) {
	    	if (root == null) {
	    		return allResult;
	    	}
	    	List<TreeNode> nodes = new LinkedList<>();
	    	preOrder(root, nodes);
	    	return allResult;
	    }
	    
	}
	
	public static void main(String[] args) {
		Binary_Tree_Paths main = new Binary_Tree_Paths();
		TreeNode root = main.new TreeNode(1);
		TreeNode l = main.new TreeNode(2);
		TreeNode r = main.new TreeNode(3);
		TreeNode lr = main.new TreeNode(5);
		root.left = l;
		root.right = r;
		l.right = lr;
		System.out.println(main.new Solution().binaryTreePaths(root));
	}
	
}
