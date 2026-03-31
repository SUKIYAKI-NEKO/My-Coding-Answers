/*
題目:骰子
來源:https://zerojudge.tw/ShowProblem?problemid=f580
*/

#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int num[200];
	int point[200][3];
	for (int i = 1; i <= n; i++) {
		num[i] = i;
		point[i][0] = 4, point[i][1] = 1, point[i][2] = 2;

	}
	for (int i = 1; i <= m; i++) {
		int f, s;
		cin >> f >> s;
		if (f > 0 && s > 0)swap(num[f], num[s]);
		if (f < 0)swap(f, s);
		f = num[f];
		if (s == -1) {
			point[f][0] = 7 - point[f][0];
			swap(point[f][0], point[f][1]);
		}
		if (s == -2) {
			point[f][2] = 7 - point[f][2];
			swap(point[f][2], point[f][1]);
		}
	}
	for (int i = 1; i <= n; i++)cout << point[num[i]][1] << " ";
	return 0;
}
