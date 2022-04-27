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
	int t;
	cin >> t;
	while(t--) {
		int n, x, qty_1a = 0, qty_2a = 0, qty_1b = 0, qty_2b = 0, sum_a = 0, sum_b = 0;
		cin >> n;
		fr(i, n) {
			cin >> x;
			if(x == 1) {
				if(qty_1a <= qty_1b) {
					qty_1a += 1;
					sum_a += 1;
				} else {
					qty_1b += 1;
					sum_b += 1;
				}
			}
			else {
				if(qty_2a <= qty_2b) {
					qty_2a += 1;
					sum_a += 2;
				} else {
					qty_2b += 1;
					sum_b += 2;
				}
			}
		}
		if(sum_a == sum_b || (sum_a - sum_b == 2 && qty_2a - qty_2b == 1 && qty_1a > 0))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}