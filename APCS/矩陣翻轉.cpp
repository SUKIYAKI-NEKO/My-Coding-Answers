/*
題目:b266. 矩陣翻轉
來源:https://zerojudge.tw/ShowProblem?problemid=b266
描述:矩陣的旋轉與翻轉
AC (2ms, 832KB)
*/

#include <iostream>
#include<algorithm>
#include<string>
using namespace std;


int main() {
    int a[255][255] = {  };
    int b[255][255] = {  };
    int r, c, m;
    cin >> r >> c >> m; //r=3,c=2
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }
    int num[255] = {};
    for (int i = 0; i < m; i++) cin >> num[i];
    for (int i = m; i > 0; i--) {
        if (num[i - 1] * (i) == (i)) {
            for (int k = 0; k < r; k++) {
                for (int j = 0; j < c; j++) {
                    b[k][j] = a[r - k - 1][j];
                }
            }
        }
        else if (num[i - 1] * (i) == 0) {
            for (int j = 0; j < c; j++) { //2
                for (int k = 0; k < r; k++) {  //3
                    b[j][k] = a[k][c - 1 - j];
                }
            }
            swap(r, c);
        }
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                a[j][k] = b[j][k];
            }
        }
    }
    cout << r << " " << c << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c - 1; j++) {
            cout << a[i][j] << " ";
        }
        cout << a[i][c - 1];
        if (i + 1 != r) cout << endl;
    }
    return 0;
}