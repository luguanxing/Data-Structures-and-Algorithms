package medium;

public class Longest_Common_Prefix {

    public String longestCommonPrefix(String[] strs) {
    	if (strs.length == 0)
    		return "";
    	//����׷�����ַ������г���
        StringBuffer sb = new StringBuffer();
        String firstStr = strs[0];
        boolean flag = true;
        int index = 0;
		//ѭ������������ƥ�������ַ������Ҳ�Խ��
        while (flag && index < firstStr.length()) {
        	sb.append(firstStr.charAt(index++));
            for (String str : strs) {
    			if (!str.startsWith(sb.toString())) {
    				flag = false;
    				break;
    			}
    		}
        }
		//��ƥ���ַ���������ֹʱҪɾ�����һ���ַ���������ƥ������ֹ����ɾ��
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
