/*
題目:機器出租
來源:https://zerojudge.tw/ShowProblem?problemid=j608
內容:Greedy
*/

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define N 100005
struct ACT{
	int s, e;
}r[N];
bool cmp(ACT p, ACT q) {
	if (p.e == q.e)return p.s < q.s;
	return p.e < q.e;
}
int t[200];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	fill(t, t + n, 0);
	for (int i = 0; i < n; i++)cin >> r[i].s;
	for (int i = 0; i < n; i++)cin >> r[i].e;
	sort(r, r + n, cmp);
	int ans = 1;
	int end = r[0].e;
	t[0] = r[0].e;
	for (int i = 1; i < n; i++) {
		int x = -1;
		int y;
		for (int j = 0; j < k; j++) {
			if (r[i].s > t[j]) {
				if (t[j] > x) {
					x = t[j];
					y = j;
				}
			}
		}
		if (x != -1) {
			t[y] = r[i].e;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
