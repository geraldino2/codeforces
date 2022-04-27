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
#define rfr(i,n)     for(int i=n-1;i>=0;i--)
 
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()
 
#define gnl cout << endl
#define uga cout << "uga" << endl
 
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int solution(int a[], int i, int n, int solutions[]) {
	int score = 0, x = a[i];
	if(i+x+1 > n) {
		score = x;
	} else {
		score = x + solutions[i+x];
	}
	return score;
}

int main() {
	fastio;
	int t, n, max_score;
	cin >> t;
	while(t--) {
		max_score = 0;
		cin >> n;
		int s[n];
		fr(i, n) {
			cin >> s[i];
		}
		int solutions[n];
		rfr(i, n) {
			solutions[i] = solution(s, i, n, solutions);
		}
		fr(i, n) {
			max_score = max(max_score, solutions[i]);
		}
		cout << max_score << endl;
	}
}
