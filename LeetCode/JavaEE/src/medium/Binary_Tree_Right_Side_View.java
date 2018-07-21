package medium;

import java.util.ArrayList;
import java.util.List;

public class Binary_Tree_Right_Side_View {

	public class TreeNode {
	    int val;
	    TreeNode left;
	    TreeNode right;
	    TreeNode(int x) { val = x; }
	}
	

	class Solution {
		
		int level = 0;
		
		List<Integer> result = new ArrayList<>();
		
		public void preOrderRight(TreeNode root, int curLevel) {
			if (root == null) {
				return;
			}
			if (curLevel > level) {
				result.add(root.val);
				level = curLevel;
			}
			preOrderRight(root.right, curLevel + 1);
			preOrderRight(root.left, curLevel + 1);
		}
		
	    public List<Integer> rightSideView(TreeNode root) {
	    	preOrderRight(root, 1);
	    	return result;
	    }
	}
	
}
