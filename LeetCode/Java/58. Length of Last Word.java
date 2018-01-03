package easy;

public class Length_of_Last_Word {

    public int lengthOfLastWord(String s) {
    	s = s.trim();
        int lastIndex = s.lastIndexOf(' ');
        String lastWord = s.substring(lastIndex+1, s.length());
    	return lastWord.length();
    }
	
	public static void main(String[] args) {
		System.out.println(new Length_of_Last_Word().lengthOfLastWord(" "));
	}

}
