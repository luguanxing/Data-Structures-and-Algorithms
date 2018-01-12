package medium;

import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;

public class Group_Anagrams {

	public class Solution {
	    public List<List<String>> groupAnagrams(String[] strs) {
	    	Map<Set, List<String>> map = new HashMap();
	    	for (String str : strs) {
				Set<String> set = new HashSet();
				String[] schars = str.split("");
				for (String schar : schars) {
					set.add(schar);
				}
				System.out.println(Arrays.toString(schars) + "->" + set);
				if (map.get(set) == null) {
					List<String> list = new LinkedList();
					list.add(str);
					Collections.sort(list);
					map.put(set, list);
				} else {
					List<String> list = map.get(set);
					list.add(str);
					Collections.sort(list);
					map.put(set, list);
				}
			}
	    	System.out.println(map);
	    	List<List<String>> retlist = new LinkedList(); 
	    	for (List<String> strslist : map.values()) {
	    		List<String> strlist = new LinkedList();
	    		for (String str : strlist) {
	    			strlist.add(str);
				}
		    	Collections.sort(strslist);
	    		retlist.add(0, strslist);
			}
	    	System.out.println(retlist);
			return retlist;
	    }
	}
	
	public static void main(String[] args) {
		Group_Anagrams main = new Group_Anagrams();
		Group_Anagrams.Solution solution = main.new Solution();
		String[] strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
		solution.groupAnagrams(strs);
	}

}
