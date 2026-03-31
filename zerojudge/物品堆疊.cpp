/*
題目:物品堆疊
來源:https://zerojudge.tw/ShowProblem?problemid=c471
內容:Greedy
*/

#include<iostream>
#include<algorithm>

using namespace std;
#define N 100010
typedef long long LL;
struct ACT{
	LL w, f; //f是加權
};
bool cmp(ACT p, ACT q) {
	return p.w * q.f < q.w * p.f;
}
int main() {
	LL n;
	cin >> n;
	ACT p[N];
	for (LL i = 0; i < n; i++)cin >> p[i].w;
	for (LL i = 0; i < n; i++)cin >> p[i].f;
	sort(p, p + n, cmp);
	LL temp=p[0].w;
	for (LL i = 1; i < n; i++) {
		LL pemp = p[i].w;
		p[i].w = temp;
		temp += pemp;
	}
	p[0].w = 0;
	LL tt = 0;
	for (LL i = 0; i < n; i++)tt += p[i].w * p[i].f;
	cout << tt<<endl;
	return 0;
}
