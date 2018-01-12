package easy;

public class Symmetric_Tree {

    public boolean isSymmetric(TreeNode left, TreeNode right) {
        if (left == null && right == null)
        	return true;
        if (left == null && right != null)
        	return false;
        if (right == null && left != null)
        	return false;
        if (left.val != right.val)
        	return false;
        //判断对称:左的左和右的右,左的右和右的左
        return isSymmetric(left.left,right.right) && isSymmetric(left.right, right.left);
    }
	
    public boolean isSymmetric(TreeNode root) {
        if (root == null)
        	return true;
        return isSymmetric(root.left, root.right);
    }
	
	public static void main(String[] args) {
		TreeNode root = new TreeNode(1);
		TreeNode node1 = new TreeNode(2);
		TreeNode node2 = new TreeNode(2);
		TreeNode node11 = new TreeNode(3);
		TreeNode node12 = new TreeNode(4);
		TreeNode node21 = new TreeNode(4);
		TreeNode node22 = new TreeNode(3);
		root.left = node1;
		root.right = node2;
		node1.left = node11;
		node1.right = node12;
		node2.left = node21;
		node2.right = node22;
		Symmetric_Tree main = new Symmetric_Tree();
		System.out.println(main.isSymmetric(root));
	}
	
}
