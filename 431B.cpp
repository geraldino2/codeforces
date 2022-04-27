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
#define dbg2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define print(x) cout << (x) << endl
#define prints(x) cout << (x) << " "

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

template<typename... T> void read(T&... args){((cin >> args), ...);}
template<typename... T> void write(T&&... args){((cout << args << " "), ...);cout << '\n';}

const char nl = '\n';

int g[5][5];
int ans=0;

void evaluate(int arr[]) {
	int happiness = g[arr[0]][arr[1]] + g[arr[2]][arr[3]] + g[arr[1]][arr[2]] + g[arr[3]][arr[4]] + g[arr[2]][arr[3]] + g[arr[3]][arr[4]];
	happiness += g[arr[1]][arr[0]] + g[arr[3]][arr[2]] + g[arr[2]][arr[1]] + g[arr[4]][arr[3]] + g[arr[3]][arr[2]] + g[arr[4]][arr[3]];
	//write(arr[0],arr[1],arr[2],arr[3],arr[4]);
	//write(happiness);
	ans = max(ans, happiness);
}

void generate_permutations(int arr[], int n, int l, int r) {
	if(l == r) evaluate(arr);
	for(int i=l; i<=r; i++) {
		swap(arr[l], arr[i]);
		generate_permutations(arr, n, l+1, r);
		swap(arr[i], arr[l]);
	}
}

void solve() {
	fr(i,5) fr(j, 5) read(g[i][j]);
	int arr[5] = {0,1,2,3,4};
	generate_permutations(arr, 5, 0, 4);
	write(ans);
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