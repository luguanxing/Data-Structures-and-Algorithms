# 拓补排序

<br>

### 拓补排序问题
```
问题:	
	在图论中，拓扑序（Topological Sorting）是一个有向无环图（DAG, Directed Acyclic Graph）
	的所有顶点的线性序列. 且该序列必须满足下面两个条件：
		1.每个顶点出现且只出现一次.
		2.若存在一条从顶点 A 到顶点 B 的路径，那么在序列中顶点 A 出现在顶点 B 的前面.
	对于一个含有n个节点的有向无环图（节点编号0到n-1），输出它的一个拓扑序.
	图的节点数和边数均不多于100000，保证输入的图是一个无环图.
```

### 拓补排序解决
```
问题:	
	每个物品要么全部取走，要么完全不取
解决:	
	假设每种物品的价值是v(i), 重量是w(i)，下标编号1-n， 背包承重是W,
	令A(n, W)计算最优决策下的物品总价值
	对于第n号物品:
		要么不拿它只考虑其前面的物品
		要么拿它并从剩下容量中考虑其它物品
	状态方程A(n, W) = max(A(n – 1, W), A(n – 1, W – w(n)) + v(n))
	初始状态即只考虑第一个物品A(0, i) = W(i);
```

### C++代码
```
请为下面的Solution类实现解决上述问题的topologicalSort函数，函数参数中n为图的节点数，edges是边集，edges[i]表示第i条边从edges[i].first指向edges[i].second. 函数返回值为有向图的一个拓扑序. 有向图有多个拓扑序时，输出任意一个即可.
 
例1：
n = 3，edges = {(0, 1), (0, 2)}，函数应返回{0, 1, 2}或者{0, 2, 1}.

例2：
n = 4，edges = {(0, 1), (0, 2), (1, 2), (3, 0)}，函数应返回{3, 0, 1, 2}.

class Solution {
public:
       vector<int> topologicalSort(int n, vector<pair<int, int>>& edges) {
        vector<int> result;
        vector<vector<int> > matrix(n);		//不用二维数组而用使用邻接矩阵表示连通图
        int degree[100000];					//入度数组，要不断找为0的
        for(int i = 0; i < n; i++)
            degree[i] = 0;
        for(int i = 0; i < edges.size(); i++){		//构造邻接矩阵和入度数组
            matrix[edges[i].first].push_back(edges[i].second);
            degree[edges[i].second]++;
        }
        int count = 0;
        stack<int> q;			//栈中保存入度为0的点
        for(int i = 0; i < n; i++)
            if(degree[i] == 0){
                count++;
                q.push(i);
            }
        while(!q.empty()){		//从栈中取出入度为0的点，同时更新它出度的点放入栈中
            int j = q.top();
            q.pop();
            result.push_back(j);
            for(int i = 0; i < matrix[j].size(); i++){
                degree[matrix[j][i]]--;
                if(degree[matrix[j][i]] == 0){
                    q.push(matrix[j][i]);
                    count++;
                }
            }
        }
        return result;
    }
};    
```

