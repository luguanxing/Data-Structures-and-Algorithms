# ��������

<br><br>

### ��������Ķ���
```
	�ڲ�������������(����)��ǰ���£�ѡ�����Ʒ��ֵ�ܺ����
```

### 0-1��������
```
����:	
	ÿ����Ʒ����ȡ(�������)һ���֣�����ȡ�ı��������Ӧ�����ļ�ֵ (������0-1֮��)
���:	
	ʹ��̰���㷨
	���ա��Լ۱ȡ���������ѡȡ���Լ۱ȡ��ϸߵ�
```

### 0/1��������
```
����:	
	ÿ����ƷҪôȫ��ȡ�ߣ�Ҫô��ȫ��ȡ
���:	
	����ÿ����Ʒ�ļ�ֵ��v(i), ������w(i)���±���1-n�� ����������W,
	��A(n, W)�������ž����µ���Ʒ�ܼ�ֵ
	���ڵ�n����Ʒ:
		Ҫô������ֻ������ǰ�����Ʒ
		Ҫô��������ʣ�������п���������Ʒ
	״̬����A(n, W) = max(A(n �C 1, W), A(n �C 1, W �C w(n)) + v(n))
	��ʼ״̬��ֻ���ǵ�һ����ƷA(0, i) = W(i);
```

<br><br><br><br><br>

### Java����
```
public int packeting(int[] w, int[]v, int c) {
	int n = w.length;
	if ( n == 0)
		return 0;
	int[][] maxValue = new int[n][c+1];
	for (int j = 0; j <= c; j++)
		maxValue[0][j] = (j >= w[0] ? v[0] : 0);
	for (int i = 1; i < n; i++)
		for (int j = 0; j <= c; j++) {
			//���õ�i����Ʒʱ
			int noTakeItemI = maxValue[i-1][j];
			maxValue[i][j] = noTakeItemI;
			if (j >= w[i]) {
				//�������õ�i����Ʒʱ
				int takeItemI = maxValue[i-1][j - w[i]] + v[i];
				maxValue[i][j] = Math.max(maxValue[i][j], takeItemI);
			}
		}
	return maxValue[n-1][c];
}
```

### C++����
```
class Solution {
public:
	int packeting(const vector<int> &w, const vector<int> &v, int c) {
		int n = w.size();
		if ( n == 0)
			return 0;
		vector<vector<int>>  maxValue(n, vector<int>(c+1,-1));
		for (int j = 0; j <= c; j++)
			maxValue[0][j] = (j >= w[0] ? v[0] : 0);
		for (int i = 1; i < n; i++)
			for (int j = 0; j <= c; j++) {
				int noTakeItemI = maxValue[i-1][j];
				maxValue[i][j] = noTakeItemI;
				if (j >= w[i]) {
					int takeItemI = maxValue[i-1][j - w[i]] + v[i];
					maxValue[i][j] = max(maxValue[i][j], takeItemI);
				}
			}
		return maxValue[n-1][c];
	}
};

int main() {
	Solution so;
	int weights[] = {1,2,3};
	int values[] ={6, 10, 12};
	int capacity = 5;
	vector<int> w(weights, weights+3);
	vector<int> v(values, values+3);
	int c = capacity;
	cout << so.packeting(w, v, c) << endl;
	return 0;
}

```
