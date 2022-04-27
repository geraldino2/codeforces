#include <bits/stdc++.h>
using namespace std;
//single colored segment (delimited by w) -> impossible
void solve(){
    bool possible=true,r=false,b=false;
    int n;cin>>n;
    char x;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x=='B')b=true;
        else if(x=='R')r=true;
        else{
            possible&=b==r==true;
            b=r=false;
        }
    }
    possible&=b==r==true;
    if(possible)cout<<"yes";else cout<<"no";
}
int main(){
    int t;cin>>t;while(t--){
        solve();
        cout<<'\n';
    }
}