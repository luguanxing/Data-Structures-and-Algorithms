package medium;

import java.util.ArrayList;
import java.util.List;

public class Path_Sum_II {

	public class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;
		TreeNode(int x) { val = x; }
	}
	
	class Solution {
		
		int curSum = 0;
		
		List<List<Integer>> allResult = new ArrayList<>();
		
		List<Integer> curResult = new ArrayList<>();
		
	    public boolean hasPathSum(TreeNode root, int sum) {
	        if (root == null) {
	        	return false;
	        } else {
	        	if (curSum + root.val == sum && root.left == null && root.right == null) {
	        		List<Integer> tempList = new ArrayList();
	        		tempList.addAll(curResult);
	        		tempList.add(root.val);
	        		allResult.add(tempList);
	        		return true;
	        	} else {
	        		curSum += root.val;
	        		curResult.add(root.val);
	        		boolean result1 = hasPathSum(root.left, sum);
	        		boolean result2 = hasPathSum(root.right, sum);
	        		curSum -= root.val;
	        		curResult.remove(curResult.size()-1);
	        		return result1 || result2;
				}
	        }
	    }
	    
	    public List<List<Integer>> pathSum(TreeNode root, int sum) {
	    	hasPathSum(root, sum);
	        return allResult;
	    }
	}
	
	public static void main(String[] args) {
		Path_Sum_II main = new Path_Sum_II();
		TreeNode root = main.new TreeNode(1);
		TreeNode node = main.new TreeNode(2);
		root.left = node;
		main.new Solution().pathSum(root, 3);
	}
	
}
