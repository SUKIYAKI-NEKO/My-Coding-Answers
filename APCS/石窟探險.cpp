/*
題目:石窟探險
來源:https://zerojudge.tw/ShowProblem?problemid=j124
內容:DFS、樹
AC (40ms, 356KB)
*/

#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
#define N 1000
typedef long long LL;
LL ans = 0;
stack<int>s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int ch;
	cin >> ch;
	if (ch % 2 == 0) {
		s.push(ch);s.push(ch);
	}
	else{
		s.push(ch); s.push(ch); s.push(ch);
	}
	while (cin >> ch) {
		int k = s.top();
		s. pop();
		if (ch == 0)continue;
		if (ch % 2 == 0) {
			s.push(ch); s.push(ch);
		}
		else {
			s.push(ch); s.push(ch); s.push(ch);
		}
		ans += abs(k - ch);
	}
	cout << ans;
	return 0;
}
