package hard;

public class Jump_Game_II {

    public int jump(int[] nums) {
    	int minStep = 0;
    	int nextTarget = 0;
    	int nextNextTarget = 0;
    	for (int step = 0; step < nums.length;) {
    		if (nextTarget >= nums.length - 1) {
    			return minStep;
    		}
    		while (step <= nextTarget) {	//设定下个最远目标,途中又找下下个最远目标
    			nextNextTarget = Math.max(nextNextTarget, step + nums[step]);
    			step++;
    		}
    		nextTarget = nextNextTarget;	//把下下个目标变成下个目标
    		minStep++;
    	}
    	return minStep;
    }
	
	public static void main(String[] args) {
		Jump_Game_II main = new Jump_Game_II();
		int[] nums = {2,3,1,1,4};
		System.out.println(main.jump(nums));;
	}

}
