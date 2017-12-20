package medium;

import java.util.Arrays;

public class Counting_Bits {
	
    public int[] countBits(int num) {
    	if (num == 0)
    		return new int[]{0};
    	int bits[] = new int[num+1];
    	bits[0] = 0;
    	bits[1] = 1;
    	//用k记录最近的幂
		int k = 0;
    	//计算bits[]
    	for (int i = 2; i <= num; i++) {
    		if ((i & (i-1)) == 0) {	//是2^k则位数为1
    			bits[i] = 1;
    			k++;
    		} else {			//是2^k+x则位数为1+bits[x]
				bits[i] = 1 + bits[(int) (i - (1 << k))];
			}
    	}
        return bits;
    }
	
	public static void main(String[] args) {
		Counting_Bits main = new Counting_Bits();
		System.out.println(Arrays.toString(main.countBits(15)));
	}

}
