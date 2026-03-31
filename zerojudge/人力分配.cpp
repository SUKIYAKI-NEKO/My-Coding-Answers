/*
題目:人力分配
來源:https://zerojudge.tw/ShowProblem?problemid=f312
*/

#include<iostream>
#include<algorithm>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;

	int a[3], b[3];
	for (int i = 0; i < 3; i++)cin >> a[i];
	for (int i = 0; i < 3; i++)cin >> b[i];
	cin >> n;
	int tt[105];
	for (int i = 0; i <= n; i++) {
		tt[i] = a[0] * i * i + a[1] * i + a[2] + b[0] * (n - i) * (n - i) + b[1] * (n - i) + b[2];
	}
	cout << *max_element(tt, tt + n + 1);
	return 0;
}
