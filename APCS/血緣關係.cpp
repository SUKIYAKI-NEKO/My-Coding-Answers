/*
題目:血緣關係
來源:https://zerojudge.tw/ShowProblem?problemid=b967
內容:樹
AC (59ms, 7.1MB)
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;
#define N 100005
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<LL>v[N];
	for (LL i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	queue<LL> q;
	q.push(0);
	LL curr;
	bool visit[N] = { false };
	while (!q.empty()) {
		curr = q.front();
		q.pop();
		visit[curr] = true;
		for (auto u : v[curr]) {
			if(!visit[u])
				q.push(u);
		}
	}
	bool visit_n[N] = {false};
	LL s[N] = { 0 };
	q.push(curr);
	LL cnt = 0;
	LL max_ans = -1;
	while (!q.empty()) {
		curr = q.front();
		max_ans = max(max_ans, s[curr]);
		visit_n[curr] = true;
		q.pop();
		for (auto u : v[curr]) {
			if (!visit_n[u]) {
				q.push(u);
				s[u] =max(s[u], s[curr] + 1);
			}
			
		}
	}
	cout << max_ans;
	return 0;
}
