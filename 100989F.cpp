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
#define lowerb(x,v) lower_bound(all(x),v)-x.begin()
#define uperb(x,v) upper_bound(all(x),v)-x.begin()

#define gnl cout << endl
#define uga cout << "uga\n"
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define dbg(x)  cout << #x << " = " << x << "\n"
#define prt(x) cout << x << "\n"
#define prtarr(x,n) fr(i,n) cout << x[i] << " ";

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

bool sortbysec(const pair <int,int> &a, const pair <int,int> &b) { return (a.snd < b.snd); }

int main() {
    fastio;
    int n, m, q, s, p, uniq_positions=0;
    cin >> n >> m >> q;
    unordered_multiset<int> covered_positions;
    unordered_map<int, int> student_position;
    fr(i, n) {
        cin >> student_position[i];
        if(covered_positions.find(student_position[i]) == covered_positions.end())
            uniq_positions++;
        covered_positions.insert(student_position[i]);
    }
    while(q--) {
        cin >> s >> p;
        s--;
        if(covered_positions.count(student_position[s])==1)
            uniq_positions--;
        covered_positions.erase(covered_positions.find(student_position[s]));
        student_position[s] = p;
        if(covered_positions.find(p) == covered_positions.end())
            uniq_positions++;
        covered_positions.insert(p);
        prt(m-uniq_positions);
    }
    return 0;
}
