/*
題目:秘密差
來源:https://zerojudge.tw/Submissions?problemid=c290&account=wasdcx0905@gmail.com&status=AC
內容:
*/

#include<iostream>
#include<string>
using namespace std;

int main() {
	string a;
	cin >> a;
	int b = a.size();
	int A = 0, B = 0;
		for (int i = b - 1; i >= 0; i -= 2) {
			A = A + a[i]-'0';
		}
		for (int i = b - 2; i >= 0; i -= 2) {
			B += a[i] - '0';
		}
		if (A - B < 0) cout << B - A;
		else cout << A - B;
	return 0;
}
