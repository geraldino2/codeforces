#include <bits/stdc++.h>
using namespace std;
void solve(){
    int rating;cin>>rating;
    if(rating<=1399)cout<<"Division 4";
    else if(rating<=1599)cout<<"Division 3";
    else if(rating<=1899)cout<<"Division 2";
    else cout<<"Division 1";
}
int main(){
    int t;cin>>t;while(t--){
        solve();
        cout<<'\n';
    }
}