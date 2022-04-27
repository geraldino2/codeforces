    #include <bits/stdc++.h>
    using namespace std;
    typedef unsigned long long ll;
    vector<ll> fact(200002);
    ll tuples(ll qty, ll m){
        if(m>qty)return 0;
        else if(m==qty)return 1;
        return (qty)*(qty-1)/2;
    }
    void solve(){
        ll n,x,k=2,m=3;
        cin>>n;
        vector<ll> seq(n);
        ll res=0;
        for(ll &x:seq)cin>>x;
        sort(seq.begin(),seq.end());
        for(int i=0;i<n;i++){
            int bound=upper_bound(seq.begin(),seq.end(),seq[i]+k)-seq.begin();
            res+=tuples(bound-i-1,m-1);
        }
        cout<<res<<endl;
    }
    int main(){
        int t;cin>>t;
        fact[0]=1;
        for(ll i=1;i<fact.size();i++)fact[i]=(fact[i-1]*i)%((ll)1e9+7);
        while(t--){
            solve();
        }
    }
