/*
題目:置物櫃分配
來源:https://zerojudge.tw/ShowProblem?problemid=e465
內容:DP
*/

#include<iostream>
#include<algorithm>

using namespace std;
#define N 100001
int box[N];
int ans[N];

int main() {
	int m,s,n;
	cin >> m>>s>>n;
	int tm = 0;
	for (int i = 1; i <= n; i++) {
		cin >> box[i];
		tm += box[i];
	}
	tm = m - tm;
	s -= tm;
	sort(box, box + n + 1);
	for (int i = 0; i <= m; i++)ans[i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = m; j > 0; j--) {
			if (box[i] > j)ans[j] = ans[j];
			else ans[j] = max(box[i] + ans[j - box[i]], ans[j]);
		}
	}
	for (int i = 0; i <= m; i++)
		if (ans[i] >= s) {
			cout << ans[i];
			return 0;
		}
	return 0;
}
