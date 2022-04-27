#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,w_al=0,w_bob=0,best=0;cin>>n;
    vector<int> w(n);
    for(int &x:w)cin>>x;
    int lp=0,rp=n-1;
    while(lp<=rp){
        if(w_al<=w_bob)w_al+=w[lp++];
        else w_bob+=w[rp--];
        if(w_al==w_bob)best=lp+n-rp-1;
    }
    cout<<best;
}
int main(){
    int t;cin>>t;while(t--){
        solve();
        cout<<'\n';
    }
}