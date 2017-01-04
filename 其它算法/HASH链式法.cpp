/*
	Description
	请用HASH链式法来解决冲突，且规定链表在链表头插入新元素。

	规定HASH函数为：h(x) = x % 11，即哈希数组下标为0～10.

	给定两种操作：

	·         I 操作，插入一个新的正整数K到哈希表中

	·         F 操作，查询整数K是否在哈希表中，若不在，输出-1；若存在，输出目前K在所在链表中的顺序索引（假定链表头索引为0）。

	Input
	 一组数据。

	第一行为整数N，0 < N <= 10000。

	接下来N行为随机出现的I操作或F操作。(数据保证K不会重复，K为大于0的int类型)

	Output
	 对于每行F操作，按顺序输出结果。
*/
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

deque<int> hash[1005];

int main() {
    int n, x, i, j;
    char c;
    cin >> n;
    while (n--) {
        cin >> c >> x;
        if (c == 'F') {
            if (find(hash[x%11].begin(), hash[x%11].end(), x) == hash[x%11].end())
                cout << "-1" << endl;
            else
                cout << find(hash[x%11].begin(), hash[x%11].end(), x) -  hash[x%11].begin() << endl;
        } else if (c == 'I') {
            hash[x%11].push_front(x);
        } else ;
    }
    return 0;
}                                        