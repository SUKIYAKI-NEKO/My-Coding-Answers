/*
題目:小群體
來源:https://zerojudge.tw/ShowProblem?problemid=c291
內容:併查集(Union and Find) 
AC (60ms, 680KB)
*/

#include <iostream>
using namespace std;
#define N 5000000
int p[N];
int f[N];
int de(int x){
    if(f[x]<0)return x;
    return f[x]=de(f[x]);
}
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i];
        f[i]=-1;
    }
    for(int i=0;i<n;i++){
        int p1,p2;
        p1=de(i);
        p2=de(p[i]);
        if(p1==p2)continue;
        if(f[p1]>f[p2]){
            f[p2]+=f[p1];
            f[p1]=p2;
        }
        else {
            f[p1]+=f[p2];
            f[p2]=p1;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
        if(f[i]<0)ans++;
    cout<<ans;
    return 0;
}
