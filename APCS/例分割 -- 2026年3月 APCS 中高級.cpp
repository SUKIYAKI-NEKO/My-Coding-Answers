/*
主題:比例分割 -- 2026年3月 APCS 中高級
來源:https://zerojudge.tw/ShowProblem?problemid=s179
內容:2分搜
AC (56ms, 4MB)
*/

#include <iostream>
using namespace std;
#define oo 100005
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    
    int w[oo];
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=2;i<=n;i++)w[i]+=w[i-1];
    
    for(int i=0;i<m;i++){
        int l,r,a,b;
        cin>>l>>r>>a>>b;
        int sd;
        if(l>1)sd=w[r]-w[l-1];
        else sd=w[r];
        int mid=(l+r)/2;
        int left=l,right=r;
        int aa;
        if(left>1)aa=w[left-1];
        else aa=0;
        while(1){
            if((w[mid-1]-aa)*(a+b)<a*sd && (w[mid]-aa)*(a+b)>=a*sd){
                cout<<mid<<endl;
                break;
            }
            else if((w[mid]-aa)*(a+b)<a*sd){
                left=mid+1;
                mid=(left+right)/2;
            }
            else if((w[mid-1]-aa)*(a+b)>=a*sd){
                right=mid-1;
                mid=(left+right)/2;
            }
        }
    }
    return 0;
}
