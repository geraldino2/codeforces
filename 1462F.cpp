#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long n;cin>>n;
    vector<long long> left(n),right(n),seqleft(n),seqright(n);
    for(long long i=0;i<n;i++)cin>>seqleft[i]>>seqright[i];
    for(long long i=0;i<n;i++)left[i]=seqleft[i],right[i]=seqright[i];
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    long long cnt=n-1;
    for(long long i=0;i<n;i++){
        long long cnt_left=n-(long long)(upper_bound(left.begin(),left.end(),seqright[i])-left.begin()); //qts da esquerda depois da direita
        long long cnt_right=lower_bound(right.begin(),right.end(),seqleft[i])-right.begin(); //qts da direita antes da esquerda
        cnt=min(cnt,cnt_right+(cnt_left>0?cnt_left:0));
    }
    cout<<cnt<<'\n';
}
int main(){
    int t;cin>>t;while(t--)solve();
}

//para toda left[i],right[i]
    //quantos segmentos tem a direita terminando antes de left[i]
    //quantos segmentos tem a esquerda comecando apos right[i]
//resposta é dada pelo mín de segmentos sobrando