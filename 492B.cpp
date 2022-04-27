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
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
 
#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)
 
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()
 
#define gnl cout << endl
#define uga cout << "uga" << endl
 
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

double max(double a, int b) {
	if(a>b)
		return a;
	return b;
}

int main() {
	fastio;
	int l, n;
	double d;
	cin >> n >> l;
	int a[n];
	fr(i, n) {
		cin >> a[i];
	}
	sort(a, a+n);
	d = a[0];
	fr(i, n-1) {
		d = max(d, (a[i+1]-a[i])/2.0);
	}
	d = max(d, l-a[n-1]);
	cout << setprecision(9) << d;
}
