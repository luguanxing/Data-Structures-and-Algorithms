package medium;

import java.util.LinkedList;
import java.util.Queue;

public class Course_Schedule {

    class Solution {
        public boolean canFinish(int numCourses, int[][] prerequisites) {
            if (prerequisites == null) {
                return false;
            }
            // 每门课的需要的前置课程数量，即入度
            int[] prerequisitesCourse = new int[numCourses];
            int finishedCourseNum = 0;
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
                finishedCourseNum++;
                for (int[] pair : prerequisites) {
                    if (pair[1] == finishedCourse) {
                        prerequisitesCourse[pair[0]]--;
                        if (prerequisitesCourse[pair[0]] == 0) {
                            planToFinishCourse.add(pair[0]);
                        }
                    }
                }
            }
            return finishedCourseNum == numCourses;
        }
    }

    public static void main(String[] args) {
        int numCourses = 6;
        int[][] prerequisites = { { 1, 0 }, { 1, 2 }, { 3, 1 }, { 1, 4 }, { 5, 3 } };
        System.out.println(new Course_Schedule().new Solution().canFinish(numCourses, prerequisites));
    }

}
