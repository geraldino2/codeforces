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

int main() {
	fastio;
	ll t, n, temp, sum_alice, sum_bob;
	cin >> t;
	while(t--) {
		bool alice = true;
		sum_alice = 0;
		sum_bob = 0;
		cin >> n;
		int s[n];
		fr(i, n) {
			cin >> s[i];
		}
		sort(s, s+n);
		stack<int> odd, even;
		fr(i, n) {
			temp = s[i];
			if(temp%2==1)
				odd.push(temp);
			else
				even.push(temp);
		}
		fr(i, n) {
			if(even.empty()) {
				if(!alice) {
					sum_bob += odd.top();
					odd.pop();
				} else {
					odd.pop();
				}
			} else if(odd.empty()) {
				if(alice) {
					sum_alice += even.top();
					even.pop();
				} else {
					even.pop();
				}
			} else if(alice) {
				if(even.top() > odd.top()) {
					sum_alice += even.top();
					even.pop();
				} else {
					odd.pop();
				}
			} else {
				if(odd.top() > even.top()) {
					sum_bob += odd.top();
					odd.pop();
				} else {
					even.pop();
				}
			}
			alice = !alice;
		}
		if(sum_alice > sum_bob)
			cout << "Alice" << endl;
		else if(sum_alice == sum_bob)
			cout << "Tie" << endl;
		else
			cout << "Bob" << endl;
	}
}
