#include "bits/stdc++.h"
using namespace std;
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")

using ll = long long;
using db = long double;
using str = string;

using vi =  vector <int>;
using vll = vector <ll>;
using pii = pair <int, int>;
using pll = pair <ll, ll>;

#define INF 1001001001
#define PI 3.1415926535897932384626
#define MOD 1000000007

#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)
#define rfr(i,n)    for(int i=n-1;i>=0;i--)

#define all(x)  x.begin(),x.end()
#define sz(x) ((int)x.size())

#define gnl cout << endl
#define uga cout << "uga" << endl
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define dbg(x)  cout << #x << " = " << x << endl

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const char nl = '\n';

void solve() {
	int n;
	cin >> n;
	ll seq[n];
	ll gcd1=0, gcd2=0;
	fr(i, n) {
		cin >> seq[i];
		if(i%2) gcd1 = __gcd(seq[i], gcd1);
		else gcd2 = __gcd(seq[i], gcd2);
	}
	if(gcd1==gcd2) { cout << "0\n"; return; }
	bool flag1=false,flag2=false,flag3=false;
	fr(i, n) {
		if(i%2==0) if(seq[i]%gcd1==0) flag1=true;
		if(i%2!=0) if(seq[i]%gcd1==0) flag2=true;
	}
	if(flag1 && flag2) flag3 = true;
	else if(gcd1>1) { cout << gcd1 << nl; return; }
	flag1=false,flag2=false;
	fr(i, n) {
		if(i%2==0) if(seq[i]%gcd2==0) flag1=true;
		if(i%2!=0) if(seq[i]%gcd2==0) flag2=true;
	}
	if(flag1 && flag2 && flag3) { cout << "0\n"; return; }
	else if(gcd2>1) { cout << gcd2 << nl; return; }
	else cout << (gcd1>gcd2?gcd1:gcd2) << nl;
}

int main() {
	fastio;
	int test_cases=1;
	cin >> test_cases;
	while(test_cases--) {
		solve();
	}
	return 0;
}