/*
主題: q836. 1. 小心陷阱
來源: https://zerojudge.tw/ShowProblem?problemid=q836
*/


#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    int x1,x2,y1,y2;
    cin>>k;
    cin>>x1>>y1;
    cin>>x2>>y2;
    int now=0;
    while(k>0){
        now+=k;
        if(now%x1==0)k-=y1;
        if(now%x2==0)k-=y2;
    }
    cout<<now;
    return 0;
}
