/*
題目:人口遷移
來源:https://zerojudge.tw/ShowProblem?problemid=f313
AC (4ms, 432KB)
*/

#include<iostream>

using namespace std;
#define oo 10000
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int r, c, k, m;
	cin >> r >> c >> k >> m;
	int a[200][200];
	for (int i = 1; i <= r; i++)for (int j = 1; j <= c; j++)
		cin >> a[i][j];
	for (int i = 0; i <= r + 1; i++)a[i][0] = a[i][c + 1] = -1;
	for (int i = 0; i <= c + 1; i++)a[0][i] = a[r + 1][i] = -1;
	int di[4] = { 1,-1,0,0 };
	int dj[4] = { 0,0,1,-1 };
	int ma = -1;
	int small = oo;

	for (int dec = 0; dec < m; dec++) {
		int b[200][200];
		for (int i = 1; i <= r; i++)for (int j = 1; j <= c; j++) {
			if (a[i][j] == -1)continue;
			b[i][j] = a[i][j] / k;
		}
		for (int i = 1; i <= r; i++)for (int j = 1; j <= c; j++) {
			if (a[i][j] == -1)continue;
			int p = 0;
			for (int s = 0; s < 4; s++) {
				int si = j + di[s], sj = i + dj[s];
				if (a[sj][si] == -1)continue;
				a[i][j] += b[sj][si];
				p++;
			}
			a[i][j] -= b[i][j] * p;
		}
	}
		
	for (int i = 1; i <= r; i++)for (int j = 1; j <= c; j++) {
		if (a[i][j] == -1)continue;
		if (a[i][j] > ma)ma = a[i][j];
		if (a[i][j] < small)small = a[i][j];
	}
	cout << small << endl << ma;
	return 0;
}
