package medium;

public class Kth_Smallest_Element_in_a_BST {

	public class TreeNode {
	    int val;
	    TreeNode left;
	    TreeNode right;
	    TreeNode(int x) { val = x; }
	}
	
	class Solution {	
		int count = 0;
		
		int kthNum = 0;
		
		private void inOrder(TreeNode root, int k) {
			if (root == null) {
				return;
			}
			inOrder(root.left, k);
			count++;
			if (count == k) {
				kthNum = root.val;
			}
			inOrder(root.right, k);
		}
		
	    public int kthSmallest(TreeNode root, int k) {
	    	inOrder(root, k);
	    	return kthNum;
	    }
	}
	
	public static void main(String[] args) {
		Kth_Smallest_Element_in_a_BST main = new Kth_Smallest_Element_in_a_BST();
		TreeNode root = main.new TreeNode(5);
		TreeNode l = main.new TreeNode(3);
		TreeNode r = main.new TreeNode(6);
		TreeNode ll = main.new TreeNode(2);
		TreeNode lr = main.new TreeNode(4);
		TreeNode lll = main.new TreeNode(1);
		root.left = l;
		root.right = r;
		l.left = ll;
		l.right = lr;
		ll.left = lll;
		System.out.println(main.new Solution().kthSmallest(root, 3));
	}
	
}
