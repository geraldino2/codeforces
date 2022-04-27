#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,x,count[200001],print=0;cin>>n;
    memset(count,0,sizeof(count));
    for(int i=0;i<n;i++){
        cin>>x;
        if(!print&&++count[x]==3){
            print=1;
            cout<<x;
        }
    }
    if(!print)cout<<"-1";
}
int main(){
    int t;cin>>t;while(t--){
        solve();
        cout<<'\n';
    }
}