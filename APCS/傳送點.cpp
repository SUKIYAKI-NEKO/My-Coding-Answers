/*
題目:傳送點
來源:https://zerojudge.tw/ShowProblem?problemid=f166
內容:DFS
AC (0.1s, 8.8MB)
*/

#include<iostream>
#include<queue>
using namespace std;
#define N 1000002
int m[N];
int t[N];
bool visit[N];
queue <int>q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, p, d[2];
	cin >> n >> p >> d[0] >> d[1];
	for (int i = 0; i < n; i++)cin >> m[i];
	q.push(0);
	d[0] = -d[0];
	t[0] = 0;
	visit[0] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (v == p) {
			cout << t[v];
			return 0;
		}
		for (int i = 0; i < 2; i++) {
			int s = m[v + d[i]];
			if (v + d[i] < 0 || v + d[i] >= n || visit[s])continue;
			if (s < 0 || s >= n)continue;
			visit[s] = true;
			t[s] = t[v] + 1;
			q.push(s);
		}
	}
	cout << -1;
	return 0;
}
