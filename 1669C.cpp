#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> seq(n);
    for(int &x:seq)cin>>x;
    int parity_one=seq[0]%2,parity_two=seq[1]%2,possible=1;
    for(int i=0;i<n;i+=2)if(seq[i]%2!=parity_one)possible=0;
    for(int i=1;i<n;i+=2)if(seq[i]%2!=parity_two)possible=0;
    if(possible)cout<<"YES";else cout<<"NO";
}
int main(){
    int t;cin>>t;while(t--){
        solve();
        cout<<'\n';
    }
}