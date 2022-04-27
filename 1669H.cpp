#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,k,x,count[31],num=0;
    memset(count,0,sizeof(count));
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x;
        for(int j=0;j<=30;j++)if(x>>j&1)count[j]++;
    }
    for(int i=30;i>=0;i--){
        if(count[i]==n)num|=1<<i;
        else if(count[i]+k>=n)k-=n-count[i],num|=1<<i;
    }
    cout<<num;
}
int main(){
    int t;cin>>t;while(t--){
        solve();
        cout<<'\n';
    }
}