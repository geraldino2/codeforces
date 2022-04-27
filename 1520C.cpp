#include "bits/stdc++.h"
using namespace std;
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")

using ll =  long long;
using db =  long double;
using str = string;

using vi =  vector <int>;
using vll = vector <ll>;
using pii = pair <int, int>;
using pll = pair <ll, ll>;

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

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const char nl = '\n';

void solve() {
	int n;
	cin >> n;
	if(n==2) {
		cout << "-1\n";
		return;
	}
	queue<int> odds, evens;
	for(int i=1; i<=(n*n)/2+(n*n)%2; i++)
		odds.push(i);
	for(int i=(n*n)/2+(n*n)%2+1; i<=(n*n); i++)
		evens.push(i);
	int matrix[n][n];
	fr(i, n) {
		fr(j, n) {
			if((i+j)%2) {
				matrix[i][j] = evens.front();
				evens.pop();
			} else {
				matrix[i][j] = odds.front();
				odds.pop();
			}
			cout << matrix[i][j] << " ";
		}
		cout << nl;
	}
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