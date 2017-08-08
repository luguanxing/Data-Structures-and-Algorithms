
public class Merge_Two_Binary_Trees {

	public static class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;
		TreeNode(int x) { val = x; }
	}
	
	public static void main(String[] args) {
		TreeNode left = null;
		TreeNode right = new TreeNode(1);
		TreeNode ret = mergeTrees(left, right);
		System.out.println(ret);
	}
	
    public static TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
    	//存在边为空则返回另一边
        if (t1 == null)
            return t2;
        if (t2 == null)
            return t1;
    	//双边均不为空则合并，向下递归
        t1.val += t2.val;
        t1.left = mergeTrees(t1.left, t2.left);
        t1.right = mergeTrees(t1.right, t2.right);
        return t1; 
    }
	
//    public static TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
//        if (t1 == null && t2 == null)
//            return null;
//		else {
//            if (t1 == null)
//                t1 = new TreeNode(0);
//            if (t2 == null)
//                t2 = new TreeNode(0);
//            DFS(t1, t2);
//            return t1;
//        }
//    }
//
//    public static void DFS(TreeNode t1, TreeNode t2) {
//    	if (t1 != null && t2 != null) {
//	    	t1.val += t2.val;
//	    	if (t1.left == null && t2.left == null && t1.right == null && t2.right == null) {
//	    		return;
//	    	} else if (t1.left != null && t2.left == null) {
//	    		t2.left = new TreeNode(0);
//	    		DFS(t1.left, t2.left);
//	    	} else if (t1.left == null &&  t2.left != null) {
//	    		t1.left = new TreeNode(0);
//	    		DFS(t1.left, t2.left);
//	    	} else if (t1.left != null && t2.left != null) {
//	    		DFS(t1.left, t2.left);
//	    	}
//	    	
//	    	if (t1.right == null && t2.right == null) {
//	    		return;
//	    	} else if (t1.right != null && t2.right == null) {
//	    		t2.right = new TreeNode(0);
//	    		DFS(t1.right, t2.right);
//	    	} else if (t1.right == null && t2.right != null) {
//	    		System.out.println(t1.val + " " + t2.val);
//	    		t1.right = new TreeNode(0);
//	    		DFS(t1.right, t2.right);
//	    	} else if (t1.right != null && t2.right != null) {
//	    		DFS(t1.right, t2.right);
//	    	}
//    	}
//    }
}
