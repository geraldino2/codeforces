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

int member_knapsack(int W, pii items[], int k) {
	int i, w;
	vector<vi> K(k+1, vi(W+1));
	for(i=0; i<=k; i++) {
		for(w=0; w<=W; w++) {
			if (i==0 || w==0) K[i][w] = 0;
			else if (items[i-1].fst <= w)
				K[i][w] = max(items[i-1].snd+K[i-1][w-items[i-1].fst],
								K[i-1][w]);
			else K[i][w] = K[i-1][w];
		}
	}
	return K[k][W];
}

int elevator_knapsack(int W, pii members[], int n) {
	int i, w;
	vector<vi> K(n+1, vi(W+1));
	for(i=0; i<=n; i++) {
		for(w=0; w<=W; w++) {
			if (i==0 || w==0) K[i][w] = 0;
			else if (members[i-1].snd <= w)
				K[i][w] = max(members[i-1].fst+K[i-1][w-members[i-1].snd],
								K[i-1][w]);
			else K[i][w] = K[i-1][w];
		}
	}
	return K[n][W];
}

void solve() {
	int n,k,l;cin>>n>>k>>l;
	pii members[n], items[k];
	fr(i,n){cin>>members[i].fst>>members[i].snd;}
	fr(i,k){cin>>items[i].fst>>items[i].snd;}
	fr(i,n) {
		members[i].fst = member_knapsack(members[i].fst, items, k);
	}
	cout << elevator_knapsack(l, members, n);
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