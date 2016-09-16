# 蛮力调度

------
利用队列结构实现车厢重排问题。车厢重排问题如下： <br>
一列货车共有n节车厢，每个车厢都有自己的编号，编号范围从1~n。给定任意次序的车厢，通过转轨站将车厢编号按顺序重新排成1~n<br>
转轨站共有k个缓冲轨，缓冲轨位于入轨和出轨之间。开始时，车厢从入轨进入缓冲轨，经过缓冲轨的重排后，按1~n的顺序进入出轨 <br>
缓冲轨按照先进先出方式，编写一个算法，将任意次序的车厢进行重排，输出每个缓冲轨中的车厢编号 <br>
(注：前一个栈只能往后一个栈调度，不能返回，用的个数越少越好)<br>

------

<br>
![image](https://github.com/luguanxing/Data-Structures-and-Algorithms/blob/master/Homework/project01-%E6%A0%88%E8%B0%83%E5%BA%A6/pic/stacks.jpg?raw=true)<br>

## 算法思路：
###第i次在A区或栈[j]找第i+1个车厢，把阻碍i+1车厢的全丢入下个栈,再把i放入B区

<br><br>
如调度(1,3,4,2)如下：<br>

![image](https://github.com/luguanxing/Data-Structures-and-Algorithms/blob/master/Homework/project01-%E6%A0%88%E8%B0%83%E5%BA%A6/pic/pic.jpg?raw=true)<br>

## 评价
因为每想到一个优化不能证明不会产生一个恶化，所以采用最简单暴力的方法
