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

#define all(x)  x.begin(),x.end()
#define sz(x) ((int)x.size())

#define gnl cout << endl
#define uga cout << "uga" << endl
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define dbg(x)  cout << #x << " = " << x << endl
#define prt(x) cout << x << "\n"
#define prtarr(x,n) fr(i,n) cout << x[i] << " ";

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {
    int n, x, minsf=INF, maxsf=-INF, gcdsf=0;
    cin >> n;
    int s[n];
    fr(i, n) {
        cin >> s[i];
        minsf = min(minsf, s[i]);
        maxsf = max(maxsf, s[i]);
    }
    // if all numbers are the same -> -1
    fr(i,n-1) {
        if(s[i]!=s[i+1]) {
            prt(-1);
            return 0;
        }
    }

    fr(i, n) {
        s[i] -= minsf;
        if(s[i]!=0)
            gcdsf = __gcd(gcdsf, s[i]);
    }
    prt(gcdsf);
}

int main() {
    fastio;
    int test_cases;
    cin >> test_cases;
    while(test_cases--) {
        solve();
    }
    return 0;
}
