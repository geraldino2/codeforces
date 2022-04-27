#include<bits/stdc++.h>
using namespace std;
 
#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define dbg2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define batata cout << "batata" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define fst first
#define snd second
typedef pair<int,int> pii;
typedef long long ll;
#define vec(x) vector< x >
#define all(x) (x).begin(),(x).end()
#define for1(i, n) for(int i=0; i<n; i++)
#define for2(i, k, n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
template<typename... T> void read(T&... args){((cin >> args), ...);}
template<typename... T> void write(T&&... args){((cout << args << " "), ...);cout << endl;}
#define print(x) cout << (x) << endl
#define prints(x) cout << (x) << " "
#define pnl() cout << endl

void solve(){
	int n,k;read(n,k);
	vec(int) v(n);
	for1(i,n)read(v[i]);
	multiset<int>s;
	ll sum=1;
	s.insert(v[0]);
	ll answer=0;
	if(k==1){
		for2(i,1,n){
			if(v[i]==v[i-1]) sum++;
			else{
				answer+=sum*(sum+1)/2;
				sum=1;
			}
		}
		answer+=sum*(sum+1)/2;
		print(answer);
		return;
	}
	for(int i=0,j=0;j<n;){
		//dbg2(i,j);
		if(j<n && sum<k){
			j++;
			if(s.find(v[j])==s.end())sum++;
			//dbg(sum);
			s.insert(v[j]);
		}
		else if(sum>k){
			s.erase(s.find(v[i]));
			if(s.find(v[i])==s.end())sum--;
			//dbg(sum);
			i++;
		}
		else if(sum==k){
			ll x=1,y=1;
			while(v[i+1]==v[i]){
				i++,x++;
			}
			while(j<n-1 && v[j+1]==v[j]){
				j++,y++;
			}
			answer+=x*y;
			i++;j++;
		}
	}
	print(answer);
}
 
int main(){
	fastio;
	int t=1;
	while(t--){
		solve();
	}
}