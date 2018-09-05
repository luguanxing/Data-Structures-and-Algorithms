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
            // 每门课的需要的前置课程数量，即入度
            int[] prerequisitesCourse = new int[numCourses];
            List<Integer> finishedCourseList = new ArrayList<>();
            for (int[] pair : prerequisites) {
                prerequisitesCourse[pair[0]]++;
            }
            // 构造BFS队列，先把入度为0即能马上学的课程加入队列
            Queue<Integer> planToFinishCourse = new LinkedList<>();
            for (int i = 0; i < prerequisitesCourse.length; i++) {
                if (prerequisitesCourse[i] == 0) {
                    planToFinishCourse.add(i);
                }
            }
            // 学习队列中的课程，每学完一门课，修改对应以该课程为基础的前置课程数量，如果能学了则加入队列中，从而实现BFS
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
