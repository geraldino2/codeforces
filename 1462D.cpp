#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,sum=0;
    cin>>n;
    vector<int> seq(n);
    for(auto &x:seq){
        cin>>x;
        sum+=x;
    }
    for(int moves=0;moves<n;moves++){
        if(sum%(n-moves)!=0)continue;
        bool possible=true;
        int desired=sum/(n-moves),curr=0;
        for(int j=0;j<n;j++){
            curr+=seq[j];
            if(curr>desired)possible=false;
            else if(curr==desired)curr=0;
        }
        if(possible&&curr==0){
            cout<<moves<<"\n";
            return;
        }
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}