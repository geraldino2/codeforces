#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;cin>>n>>m;
    char grid[n][m];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>grid[i][j];
    for(int t=0;t<=n;t++)for(int i=n-2;i>=0;i--)for(int j=0;j<m;j++)
        if(grid[i][j]=='*'&&grid[i+1][j]=='.')grid[i][j]='.',grid[i+1][j]='*';
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cout<<grid[i][j];
        cout<<'\n';
    }
}
int main(){
    int t;cin>>t;while(t--){
        solve();
        cout<<'\n';
    }
}