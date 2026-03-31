/*
題目:字串操作
來源:https://zerojudge.tw/ShowProblem?problemid=q182
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	long long k;
	cin >> k;
	int len = s.length();
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		if (a == 0) {
			for (int i = 0; i < len; i+=2)swap(s[i], s[i + 1]);
		}
		else if (a == 1) {
			for (int i = 0; i < len; i += 2)
				if (s[i] > s[i + 1])swap(s[i], s[i + 1]);
		}
		else {
			string s1;
			string s2;
			for (int i = 0; i < len / 2; i++) {
				s1.push_back(s[i]);
				s2.push_back(s[len / 2 + i]);
			}
			for (int i = 0,j=0; i < len; i += 2,j++) {
				s[i] = s1[j];
				s[i + 1] = s2[j];
			}
		}
	}
	cout << s;
	return 0;
}
