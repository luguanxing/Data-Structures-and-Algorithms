package medium;

public class Longest_Common_Prefix {

    public String longestCommonPrefix(String[] strs) {
    	if (strs.length == 0)
    		return "";
    	//不断追加子字符串进行尝试
        StringBuffer sb = new StringBuffer();
        String firstStr = strs[0];
        boolean flag = true;
        int index = 0;
		//循环条件：不断匹配所有字符串并且不越界
        while (flag && index < firstStr.length()) {
        	sb.append(firstStr.charAt(index++));
            for (String str : strs) {
    			if (!str.startsWith(sb.toString())) {
    				flag = false;
    				break;
    			}
    		}
        }
		//是匹配字符串导致终止时要删除最后一个字符，否则是匹配完终止不用删除
        if (!flag)
        	sb.deleteCharAt(sb.length()-1);
    	return sb.toString();
    }
	
	public static void main(String[] args) {
		Longest_Common_Prefix main = new Longest_Common_Prefix();
		String[] strs = {"afd", "afc"};
		System.out.println(main.longestCommonPrefix(strs));
	}

}
