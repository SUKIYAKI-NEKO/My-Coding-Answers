/*
題目:數字龍捲風 
來源:https://zerojudge.tw/ShowProblem?problemid=c292
AC (3ms, 796KB)
*/

#include<iostream>
#include<utility>
#include<vector>
using namespace std;
#define N 100
typedef long long LL;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int c;
	cin >> c;
	int ma[N][N];
	for (int i = 1; i <= n; i++)for (LL j = 1; j <= n; j++)
		cin >> ma[i][j];
	for (int i = 0; i <= n; i++)ma[i][0] = ma[i][n+1] = -1;
	for (int i = 0; i <= n; i++)ma[0][i] = ma[n+1][i] = -1;
	int ni = n / 2 + 1, nj = n / 2 + 1;
	vector<int>v;
	v.push_back(ma[nj][ni]);
	if (c == 0) {
		int d = 0;
		while (ma[nj][ni]>=0) {
			d++;
			for (int i = 0; i < d; i++)v.push_back(ma[nj][--ni]);
			for (int i = 0; i < d; i++)v.push_back(ma[--nj][ni]);
			d++;
			for (int i = 0; i < d; i++)v.push_back(ma[nj][++ni]);
			for (int i = 0; i < d; i++)v.push_back(ma[++nj][ni]);
		}
	}
	else if (c == 1) {
		int d = 0;
		while (ma[nj][ni] >= 0) {
			d++;
			for (int i = 0; i < d; i++)v.push_back(ma[--nj][ni]);
			for (int i = 0; i < d; i++)v.push_back(ma[nj][++ni]);
			d++;
			for (int i = 0; i < d; i++)v.push_back(ma[++nj][ni]);
			for (int i = 0; i < d; i++)v.push_back(ma[nj][--ni]);
		}
	}
	else if (c == 2) {
		int d = 0;
		while (ma[nj][ni] >= 0) {
			d++;
			for (int i = 0; i < d; i++)v.push_back(ma[nj][++ni]);
			for (int i = 0; i < d; i++)v.push_back(ma[++nj][ni]);
			d++;
			for (int i = 0; i < d; i++)v.push_back(ma[nj][--ni]);
			for (int i = 0; i < d; i++)v.push_back(ma[--nj][ni]);
		}
	}
	else {
		int d = 0;
		while (ma[nj][ni] >= 0) {
			d++;
			for (int i = 0; i < d; i++)v.push_back(ma[++nj][ni]);
			for (int i = 0; i < d; i++)v.push_back(ma[nj][--ni]);
			
			d++;
			for (int i = 0; i < d; i++)v.push_back(ma[--nj][ni]);
			for (int i = 0; i < d; i++)v.push_back(ma[nj][++ni]);
		}
	}
	for (auto i = v.begin(); i != v.end(); i++) {
		if (*i < 0)break;
		cout << *i;
	}
	return 0;
}
