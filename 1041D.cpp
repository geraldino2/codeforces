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

using vi =  vector <int>;
using vll = vector <ll>;
using pii = pair <int, int>;
using pll = pair <ll, ll>;

#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)
#define rfr(i,n)    for(int i=n-1;i>=0;i--)
#define bfr(i,n,b)  for(int i=b;i<n;i++)

#define all(x)  x.begin(),x.end()
#define sz(x) ((int)x.size())
#define lowerb(x,v) lower_bound(all(x),v)-x.begin()
#define uperb(x,v) upper_bound(all(x),v)-x.begin()

#define gnl cout << endl
#define uga cout << "uga\n"
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define dbg(x)  cout << #x << " = " << x << "\n"
#define prt(x) cout << x << "\n"
#define prtarr(x,n) fr(i,n) cout << x[i] << " "

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

bool sortbysec(const pair <int,int> &a, const pair <int,int> &b) { return (a.snd < b.snd); }

int main() {
	fastio;
	int n, h, temp, last_extra=0;
	cin >> n >> h;
	int safesum[n], area[n];
	vi positions;
	ll distances[n];
	fr(i, n) {
		cin >> temp; positions.pb(temp);
		cin >> temp; area[i] = temp - positions[i];
	}
	safesum[0] = area[0];
	frr(i, n-1) {
		safesum[i] = safesum[i-1] + area[i];
	}
	ll temp_position, extra;
	distances[0] = safesum[0] + h;
	temp_position = positions[0] + distances[0];
	fr(i, n) {
		if(i>0)
			distances[i] = safesum[i] - safesum[i-1] + h;
		else
			distances[i] = safesum[i] + h;
		temp_position = positions[i] + distances[i];
	}
	prt(*max_element(distances, distances+n));
	return 0;
}
