#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD=1e9+7;
vector<ll> fact(200002),invfact(200002);
ll pow(ll x, ll y, ll p) {
    x = x%p;
    ll res = 1;
    if(x == 0)
        return 0;
    while(y>0) {
        if(y&1)
            res = (res*x)%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return res;
}
ll tuples(ll qty, ll m){
    if(m>qty)return 0;
    else if(m==qty)return 1;
    return fact[qty]*invfact[m]%MOD*invfact[qty-m]%MOD;
}
void solve(){
    ll n,x,k=2,m=3;
    cin>>n>>m>>k;
    vector<ll> seq(n);
    ll res=0;
    for(ll &x:seq)cin>>x;
    sort(seq.begin(),seq.end());
    for(int i=0;i<n;i++){
        int bound=upper_bound(seq.begin(),seq.end(),seq[i]+k)-seq.begin();
        res=(res+tuples(bound-i-1,m-1))%MOD;
    }
    cout<<res<<endl;
}
int main(){
    int t;cin>>t;
    fact[0]=1,invfact[0]=1;
    for(ll i=1;i<fact.size();i++){
        fact[i]=(fact[i-1]*i)%MOD;
        invfact[i]=pow(fact[i],MOD-2,MOD);
    }
    while(t--){
        solve();
    }
}
