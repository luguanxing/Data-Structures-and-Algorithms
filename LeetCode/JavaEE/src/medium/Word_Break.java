package medium;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Word_Break {

    class Solution {
        public boolean wordBreak(String s, List<String> wordDict) {
            boolean[] continueIndex = new boolean[s.length()];
            for (int right = 0; right < s.length(); right++) {
                if (wordDict.contains(s.substring(0, right + 1))) {
                    continueIndex[right] = true;
                    continue;
                }
                for (int left = 0; left < right; left++) {
                    if (continueIndex[left] == true && wordDict.contains(s.substring(left + 1, right + 1))) {
                        continueIndex[right] = true;
                    }
                }
            }
            return continueIndex[s.length() - 1];
        }
    }

    // 暴力枚举超时了
    class Solution_TLE {
        boolean flag = false;

        public boolean wordBreak(String s, List<String> wordDict) {
            for (String word : wordDict) {
                matchPrefix(s, word, wordDict);
            }
            return flag;
        }

        public void matchPrefix(String s, String prefix, List<String> wordDict) {
            if (s.startsWith(prefix)) {
                String sLast = s.substring(prefix.length(), s.length());
                if (sLast.length() == 0) {
                    flag = true;
                    return;
                } else {
                    for (String word : wordDict) {
                        matchPrefix(sLast, word, wordDict);
                    }
                }
            } else {
                return;
            }
        }
    }

    public static void main(String[] args) {
        String s = "catsandog";
        List<String> wordDict = new ArrayList<>();
        wordDict.add("cats");
        wordDict.add("dog");
        wordDict.add("sand");
        wordDict.add("and");
        wordDict.add("cat");
        System.out.println(new Word_Break().new Solution().wordBreak(s, wordDict));
    }

}
