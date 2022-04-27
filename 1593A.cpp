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
#define uga cout << "uga\n"
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define dbg(x)  cout << #x << " = " << x << "\n"
#define prt(x) cout << x << "\n"
#define prtarr(x,n) fr(i,n) cout << x[i] << " ";

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll a, b, c, max_votes;

ll votes(ll vote) {
    if(vote == max_votes)
        if((a==b && a==max_votes) || (b==c && b==max_votes) || (a==c && c==max_votes))
            return 1;
        else
            return 0;
    else
        return (max_votes+1)-vote;
}

int main() {
    fastio;
    int test_cases;
    cin >> test_cases;
    while(test_cases--) {
        cin >> a >> b >> c;
        max_votes = max(a, max(b, c));
        if(a==b && b==c)
            cout << "1 1 1\n";
        else
            cout << votes(a) << " " << votes(b) << " " << votes(c) << "\n";
    }
    return 0;
}
