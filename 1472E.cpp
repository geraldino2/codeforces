#include "bits/stdc++.h"
using namespace std;
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")

typedef long long ll;
typedef long double db;
typedef string str;

typedef vector <int> vi;
typedef vector <ll> vll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

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
    auto bothsmallercomp = [&](pii e1, pii e2) {
        return e1.first<e2.first && e1.second<e2.second;
    };
    int n, h, w;
    cin >> n;
    map<pii, int> positions;
    map<int, pii> reversepositions;
    vector<pii> people;
    fr(i, n) {
        cin >> h >> w;
        pii hwsize = mp(h, w);
        people.pb(hwsize);
        positions[hwsize] = i+1;
        reversepositions[i+1] = hwsize;
    }
    sort(all(people));
    frr(i, n) {
        int found = -1;
        auto it = lower_bound(all(people), mp(reversepositions[i].fst, reversepositions[i].snd), bothsmallercomp);
        if(it != people.end()) {
            pii p = *it;
            found = positions[p];
            dbg(reversepositions[i].fst);
            dbg(reversepositions[i].snd);
            dbg(p.fst);
            dbg(p.snd);
            dbg(found);
        }
        /*else {
            auto it = lower_bound(all(people), mp(reversepositions[i].snd-1, reversepositions[i].fst-1));
            if(it != people.end())
                found = positions[people[it - people.begin()]];
        }*/
        cout << found << " ";
    }
    gnl;
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
