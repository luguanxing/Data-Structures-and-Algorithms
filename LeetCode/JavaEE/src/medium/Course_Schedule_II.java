package medium;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Course_Schedule_II {

    class Solution {
        public int[] findOrder(int numCourses, int[][] prerequisites) {
            if (prerequisites == null) {
                return null;
            }
            // ÿ�ſε���Ҫ��ǰ�ÿγ������������
            int[] prerequisitesCourse = new int[numCourses];
            List<Integer> finishedCourseList = new ArrayList<>();
            for (int[] pair : prerequisites) {
                prerequisitesCourse[pair[0]]++;
            }
            // ����BFS���У��Ȱ����Ϊ0��������ѧ�Ŀγ̼������
            Queue<Integer> planToFinishCourse = new LinkedList<>();
            for (int i = 0; i < prerequisitesCourse.length; i++) {
                if (prerequisitesCourse[i] == 0) {
                    planToFinishCourse.add(i);
                }
            }
            // ѧϰ�����еĿγ̣�ÿѧ��һ�ſΣ��޸Ķ�Ӧ�Ըÿγ�Ϊ������ǰ�ÿγ������������ѧ�����������У��Ӷ�ʵ��BFS
            while (planToFinishCourse.size() != 0) {
                Integer finishedCourse = planToFinishCourse.poll();
                finishedCourseList.add(finishedCourse);
                for (int[] pair : prerequisites) {
                    if (pair[1] == finishedCourse) {
                        prerequisitesCourse[pair[0]]--;
                        if (prerequisitesCourse[pair[0]] == 0) {
                            planToFinishCourse.add(pair[0]);
                        }
                    }
                }
            }
            if (finishedCourseList.size() == numCourses) {
                int[] orders = new int[numCourses];
                for (int i = 0; i < numCourses; i++) {
                    orders[i] = finishedCourseList.get(i);
                }
                return orders;
            } else {
                return new int[] {};
            }
        }
    }
    
    public static void main(String[] args) {
        int numCourses = 6;
        int[][] prerequisites = { { 1, 0 }, { 1, 2 }, { 3, 1 }, { 1, 4 }, { 5, 3 } };
        System.out.println(Arrays.toString(new Course_Schedule_II().new Solution().findOrder(numCourses, prerequisites)));
    }

}
