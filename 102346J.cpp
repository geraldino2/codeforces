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

int next(int x, int n) {
	if(x==n-1)
		return 0;
	else
		return x+1;
}

bool comp(char a, char b) {
	str dictionary = "A23456789DQJK";
	return(dictionary.find(a) < dictionary.find(b));
}

int next_card(str x) {
	str temp = x;
	sort(temp.begin(), temp.end(), comp);
	int counts[temp.length()];
	fr(i, temp.length()) {
		counts[i] = count(all(temp),temp[i]);
	}
	int min_index=0, min_count=5;
	fr(i, temp.length()) {
		if(counts[i] < min_count) {
			min_index = i;
			min_count = counts[i];
		}
	}
	return(x.find(temp[min_index]));
}

int main() {
	fastio;
	int n, k, curr, curr_joker, joker_status=0, nextcard, nextplayer;
	cin >> n >> k;
	k--;
	curr_joker = k;
	str deques[n];
	fr(i, n) {
		cin >> deques[i];
	}
	fr(i, n) {
		if(deques[i][0]==deques[i][1] && deques[i][0]==deques[i][2] && deques[i][0]==deques[i][3] && i!=k) {
			cout << i+1;
			return 0;
		}
	}
	while(1) {
		nextplayer = next(k, n);
		if(k==curr_joker) {
			if(joker_status==1) {
				curr_joker = nextplayer;
				joker_status = 0;
			} else {
				joker_status++;
				nextcard = next_card(deques[k]);
				str temp = "";
				fr(i, deques[k].length()) {
					if(i != nextcard)
						temp += deques[k][i];
				}
				deques[nextplayer] += deques[k][nextcard];
				deques[k] = temp;
			}
		} else {
			nextcard = next_card(deques[k]);
			str temp = "";
			fr(i, deques[k].length()) {
				if(i != nextcard)
					temp += deques[k][i];
			}
			deques[nextplayer] += deques[k][nextcard];
			deques[k] = temp;
		}
		if(deques[k][0]==deques[k][1] && deques[k][0]==deques[k][2] && deques[k][0]==deques[k][3] && k!=curr_joker) {
			cout << k+1;
			return 0;
		}
		k = nextplayer;
	}
	cout << k+1;
}
