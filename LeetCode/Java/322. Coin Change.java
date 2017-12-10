package medium;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.TreeSet;

public class Coin_Change {
	
	private int state[];
	
    public int coinChange(int[] coins, int amount) {
    	state = new int[amount+1];
    	state[0] = 0;
    	for (int i = 1; i <= amount; i++) {	//不断向后计算state[i]直到state[amount]
    		Set<Integer> set = new TreeSet();
    		for (int coin : coins) {
				if (i - coin < 0)
					continue;
				if (state[i - coin] != -1)
					set.add(state[i - coin]);
			}
    		if (set.isEmpty()) {
    			state[i] = -1;
    		} else {
    			Iterator<Integer> it = set.iterator();
    			if (it.hasNext())
    				state[i] = it.next() + 1;
    		}
    	}
    	for (int i = 0; i <= amount; i++)
    		System.out.print(state[i] + " ");
    	System.out.println();
        return state[amount];
    }
    
    public static void main(String[] args) {
    	Coin_Change main = new Coin_Change();
    	int amount = 8440;
    	int coins[] = {429,171,485,26,381,31,290};
    	System.out.println(main.coinChange(coins, amount));;
	}
    
}
