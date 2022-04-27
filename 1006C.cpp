#include "bits/stdc++.h"
using namespace std;
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
 
using ll = long long;
using db = long double;
using str = string;
 
#define INF 1001001001
#define PI 3.1415926535897932384626
 
#define pii pair<int, int>
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
 
#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)
#define rfr(i,n)     for(int i=n-1;i>=0;i--)
 
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()
 
#define gnl cout << endl
#define uga cout << "uga" << endl
 
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) { return (a.snd < b.snd); }

int main() {
	fastio;
	int n, lp, rp;
	ll sum_l, sum_r, sum=0;
	cin >> n;
	int s[n];
	fr(i, n) {
		cin >> s[i];
	}
	lp = 0;
	rp = n-1;
	sum_l = s[0];
	sum_r = s[n-1];
	while(sum_l != sum_r || lp < rp) {
		if(sum_l == sum_r) {
			sum = sum_l;
			lp++;
			sum_l += s[lp];
		} else if(sum_l < sum_r) {
			lp++;
			sum_l += s[lp];
		} else {
			rp--;
			sum_r += s[rp];
		}
	}
	cout << sum;
}
