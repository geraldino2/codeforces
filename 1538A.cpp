#include "bits/stdc++.h"
using namespace std;
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")

using ll = long long;
using db = long double;
using str = string;

using vi =  vector <int>;
using vll = vector <ll>;
using pii = pair <int, int>;
using pll = pair <ll, ll>;

#define INF 1001001001
#define PI 3.1415926535897932384626

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

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const char nl = '\n';

void solve() {
    int n;
    cin >> n;
    int seq[n];
    int mn=101, imn=-1, mx=0, imx=-1;
    fr(i, n) {
        cin >> seq[i];
        if(seq[i]<mn) { mn=seq[i]; imn=i; }
        if(seq[i]>mx) { mx=seq[i]; imx=i; }
    }
    int destroying_all_from_left, destroying_all_from_right, destroying_all_from_sides;
    destroying_all_from_left = max(imn, imx)+1;
    destroying_all_from_right = n-min(imn, imx);
    if(imn>imx) { imn^=imx; imx^=imn; imn^=imx; }
    destroying_all_from_sides = imn+1+n-imx;
    cout << min(destroying_all_from_left, min(destroying_all_from_right, destroying_all_from_sides)) << nl;
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