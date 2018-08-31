package easy;

import java.util.Arrays;

public class Assign_Cookies {

    class Solution {
        // 简化后的方法
        public int findContentChildren(int[] g, int[] s) {
            Arrays.sort(g);
            Arrays.sort(s);
            int gi = 0;
            int si = 0;
            while (gi < g.length && si < s.length) {
                if (g[gi] <= s[si]) {
                    gi++;
                }
               si++;
            }
            return gi;
        }
        
        // 判断逻辑过于复杂，方法不够简洁
        public int findContentChildren_v0(int[] g, int[] s) {
            if (g == null || g.length == 0 || s == null || s.length == 0) {
                return 0;
            }
            Arrays.sort(g);
            Arrays.sort(s);
            int gMax = g[g.length - 1];
            int gMin = g[0];
            int sMax = s[s.length - 1];
            int sMin = s[0];
            if (sMax < gMin) {
                return 0;
            }
            if (gMax < sMin) {
                if (g.length < s.length) {
                    return g.length;
                } else {
                    return s.length;
                }
            }
            int si = 0;
            int gi = 0;
            for (gi = 0; gi < g.length;) {
                while (si < s.length && s[si] < g[gi]) {
                    si++;
                }
                if (si >= s.length) {
                    break;
                }
                System.out.println(g[gi] + " -> " + s[si]);
                gi++;
                si++;
            }
            return gi;
        }
    }

    public static void main(String[] args) {
        int[] g = { 11, 12, 13, 14, 15, 16 };
        int[] s = { 8, 9, 13, 14, 15, 20, 21 };
        System.out.println(new Assign_Cookies().new Solution().findContentChildren(g, s));
        int[] g_ = { 1, 2, 3 };
        int[] s_ = { 1, 1};
        System.out.println(new Assign_Cookies().new Solution().findContentChildren(g_, s_));
    }

}
