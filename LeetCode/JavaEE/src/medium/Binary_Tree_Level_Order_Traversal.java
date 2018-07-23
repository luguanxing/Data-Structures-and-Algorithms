package medium;

import java.util.ArrayList;
import java.util.List;

public class Binary_Tree_Level_Order_Traversal {

	public class TreeNode {
	    int val;
	    TreeNode left;
	    TreeNode right;
	    TreeNode(int x) { val = x; }
	    @Override
	    public String toString() {
	    	return "" + val;
	    }
	}
	
	class Solution {
		
		List<List<Integer>> levels = new ArrayList<>();
		
		int level = 0;
		
		public void preOrder(TreeNode root, int curLevel) {
			if (root == null) {
				return;
			}
			if (curLevel > level) {
				List<Integer> newLevel  = new ArrayList<>();
				newLevel.add(root.val);
				levels.add(newLevel);
				level++;
			} else {
				List<Integer> nowLevel = levels.get(curLevel - 1);
				nowLevel.add(root.val);
			}
			preOrder(root.left, curLevel+1);
			preOrder(root.right, curLevel+1);
		}
		
	    public List<List<Integer>> levelOrder(TreeNode root) {
	    	preOrder(root, 1);
	    	return levels;
	    }
	}
	
	public static void main(String[] args) {
		Binary_Tree_Level_Order_Traversal main = new Binary_Tree_Level_Order_Traversal();
		TreeNode root = main.new TreeNode(1);
		TreeNode l = main.new TreeNode(2);
		TreeNode r = main.new TreeNode(3);
		TreeNode ll = main.new TreeNode(4);
		TreeNode lr = main.new TreeNode(5);
		root.left = l;
		root.right = r;
		l.left = ll;
		l.right = lr;
		System.out.println(main.new Solution().levelOrder(root));
	}
	
}
