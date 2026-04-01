/*
題目:貨物分配
來源:https://zerojudge.tw/ShowProblem?problemid=f163
內容:樹
AC (95ms, 4.2MB)
*/

#include<iostream>
#include<algorithm>
using namespace std;
#define N 10000000
struct {
	int left, right;
}co[N]; //節點
int w[N];
int in[N];
int ans[N];
int n, m;
int load(int x) {
    if (w[x]>=0)return w[x]; 
	w[x] = load(co[x].left) + load(co[x].right);
	return w[x];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> w[n + i];
	for (int i = 0; i < n; i++)w[i] = -1;
	for (int i = 0; i < m; i++)cin >> in[i];
	for (int i = 0; i < n - 1; i++) {
		int a;
		cin >> a;
		cin >> co[a].left >> co[a].right;
	}
	load(1);
	for (int i = 0; i < m; i++) {
		int v = in[i];
		w[1] += v;
		int d = 1;
		while (1) {
			if (w[co[d].left] <= w[co[d].right])
				d = co[d].left;
			else d = co[d].right;
			w[d] += v;
			if (d >= n)break;
		}
		ans[i] = d;
	}
	for (int i = 0; i < m; i++)cout << ans[i] << " ";
	return 0;
}
