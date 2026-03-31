/*
題目:蒐集寶石
來源:https://zerojudge.tw/ShowProblem?problemid=o712
*/

#include<iostream>

using namespace std;
int map[102][102];
int main() {
	int m, n, k, r, c;
	cin >> m >> n >> k >> r >> c;
	for (int i = 0; i < m; i++)for (int j = 0; j < n; j++)
		cin >> map[i][j];
	int d = 4; //1上 2下 3左 4右
	int score = 0;
	int ans = 0;
	while (1) {
		bool df = false;
		if (map[r][c] == 0)break;
		score += map[r][c];
		ans++;
		map[r][c]--;
		while(1)
			if (d == 1) {
				if (r - 1 < 0 || map[r-1][c] == -1) {
					d = 4;
					df = true;
					continue;
				}
				if (score % k == 0 && !df) {
					d = 4;
					df = true;
					continue;
				}
				r--; break;
			}
			else if (d == 2) {
				if (r+1 >= m || map[r+1][c] == -1) {
					d = 3;
					df = true;
					continue;
				}
				if (score % k == 0 && !df) {
					d = 3;
					df = true;
					continue;
				}
				r++; break;
			}
			else if (d == 3) {
				if (c - 1 <0 || map[r][c - 1] == -1) {
					d = 1;
					df = true;
					continue;
				}
				if (score % k == 0 && !df) {
					d = 1;
					df = true;
					continue;
				}
				c--; break;
			}
			else {
				if (c + 1 >= n||map[r][c+1]==-1) {
					d = 2;
					df = true;
					continue;
				}
				if (score % k == 0&&!df) {
					d = 2;
					df = true;
					continue;
				}
				c++; break;
			}
	}
	cout << ans;
	return 0;
}
