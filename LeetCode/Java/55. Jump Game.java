package medium;

import java.util.LinkedList;
import java.util.Queue;

public class Jump_Game {

    public static boolean canJump(int[] nums) {  
    	int reachMax = 0;	//����Զ���ﷶΧ
    	int stepIndex = 0;	//��ǰ�ߵ������
    	for (stepIndex = 0; stepIndex <= reachMax && stepIndex < nums.length; stepIndex++) {
    		reachMax = Math.max(reachMax, stepIndex + nums[stepIndex]);		///������������Զ���ﷶΧ
    	}
    	return stepIndex >= nums.length;
    }  
	
//    ʹ��BFS�����ϳ�ʱ
//    public static boolean canJump(int[] nums) {
//    	if (nums == null || nums.length ==0)
//    		return false;
//    	if (nums.length == 1)
//    		return true;
//    	boolean[] isJumped = new boolean[nums.length];
//    	isJumped[0] = true;
//    	Queue<Integer> queue_next = new LinkedList<Integer>();
//    	Queue<Integer> queue_index = new LinkedList<Integer>();
//    	queue_next.add(nums[0]);
//    	queue_index.add(0);
//    	while(!queue_next.isEmpty()) {
//    		int next = queue_next.poll();
//    		int index = queue_index.poll();
//    		if (next > nums.length - 1 - index)
//    			next =  nums.length - 1 - index;
//    		for (int i = next; i >= 1; i--) {
//    			if (index + i == nums.length - 1)
//    				return true;
//    			if (!isJumped[index+i]) {
//    				isJumped[index+i] = true;
//    				queue_next.add(nums[index+i]);
//    				queue_index.add(index+i);
//    			}
//    		}
//    	}
//    	return false;
//    }
    
	
	public static void main(String[] args) {
		int[] nums = {2,3,1,1,4};
		System.out.println(canJump(nums));
	}

}
