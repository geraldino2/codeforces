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
 
int main() {
	fastio;
	int t, n, w, h, s;
	cin >> t;
	while(t--) {
		s = 1;
		cin >> w >> h >> n;
		while(w%2==0 || h%2==0) {
			if(w%2==0) {
				s*=2;
				w/=2;
			}
			if(h%2==0) {
				s*=2;
				h/=2;
			}
		}
		if(s>=n)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}