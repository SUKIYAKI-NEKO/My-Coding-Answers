/*
題目:b966. 線段覆蓋長度
來源:https://zerojudge.tw/ShowProblem?problemid=b966
內容:
*/

#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
#define N 100010
struct ACT{
	LL right, left;
};
bool cmp(ACT p, ACT q) {
	if (p.left > q.left)return false;
	return true;
}
int main() {
	LL n;
	cin >> n;
	ACT s[N];
	for (LL i = 0; i < n; i++) {
		cin >> s[i].left >> s[i].right;
	}
	sort(s, s + n, cmp);
	auto ma = s[0];
	LL tt = 0;
	for (LL i = 1; i < n; i++) {
		if (ma.right < s[i].left) {
			tt += ma.right - ma.left;
			ma = s[i];
			continue;
		}
		ma.right = max(ma.right, s[i].right);
	}
	tt += ma.right - ma.left;
	cout << tt;
	return 0;
}
