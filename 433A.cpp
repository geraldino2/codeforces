#include "bits/stdc++.h"
using namespace std;
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
 
typedef long long       ll;
typedef long double     db;
typedef string          str;
typedef vector <int>    vi;
typedef vector <ll>     vll;
typedef pair <int, int> pii;
typedef pair <ll, ll>   pll;
 
#define INF 1001001001
#define PI  3.1415926535897932384626
#define MOD 1000000007
 
#define eb  emplace_back
#define pb  push_back
#define mp  make_pair
#define mt  make_tuple
#define fst first
#define snd second
 
#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)
#define rfr(i,n)    for(int i=n-1;i>=0;i--)
 
#define all(x)      x.begin(),x.end()
#define sz(x)       ((int)x.size())
#define ms(a,x)     memset(a,x,sizeof(a))
 
#define gnl cout << endl
#define uga cout << "uga" << endl
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define dbg(x) cout << #x << " = " << x << endl
#define dbg2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define print(x) cout << (x) << endl
#define prints(x) cout << (x) << " "
 
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
template<typename... T> void read(T&... args){((cin >> args), ...);}
template<typename... T> void write(T&&... args){((cout << args << " "), ...);cout << '\n';}
 
const char nl = '\n';
 
void solve() {
	int c,cnt1=0,cnt2=0,aux,n;read(n);
    vi seq(n);
	for(int &x:seq) {
		read(x);if(x==200)cnt2++;else cnt1++;
	}
    if((100*cnt1+200*cnt2)%2)no;else{
        c=(100*cnt1+200*cnt2)/2;
        aux=0;
        sort(all(seq));
        for(int i=n-1;i>=0;i--){
            aux+=seq[i];
            if(seq[i]==100)cnt1--;else cnt2--;
            if(aux==c){
                yes;return;
            } else if(aux>c){
                if(aux-c==100&&cnt1>0){
                    yes;return;    
                } else {
                    no;return;
                }
            }
        }
    }
}
 
int main() {
	fastio;
	int test_cases=1;
	//cin >> test_cases;
	while(test_cases--) {
		solve();
	}
	return 0;
}
