#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;
//#define endl '\n'
#define br cout<<endl
#define mem(a) memset(a,0,sizeof(a))
const double pi=3.141592653589793238;
#define d(x) cout<<x<<endl;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define rev(a) reverse(a.begin(),a.end())
const int inf = 2*(1e18);
#define maxn 1000005
#define mod 998244353
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()
#define f(i,n) for(int i=1;i<=n;i++)
#define fp(i,k,n) for(int i=k;i<=n;i+=1)
#define fn(i,k,n) for(int i=k;i>=n;i-=1)
void pv(vector<int> v){  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<endl;}
void pa(int a[],int n,int p){for (int i = p; i < n+p; ++i){cout<<a[i]<<" ";}cout<<endl;}
int modexp(int x,int y) {
	 int res = 1;
	 x = x % mod;
	 while (y > 0){
			 if (y & 1LL)
					 res = (res*x) % mod;
			 y = y>>1;
			 x = (x*x) % mod;  
	 }
	 return res;
}
int invmod(int a) {
		return modexp(a,mod-2);
}
vector<int> edge[maxn];
void ipgraph(int n,int m) {
		fp(i,1,n) edge[i].clear();
		if(m==0) return;
	 fp(i,1,m) {
			 int a,b;
			 cin>>a>>b;
			 edge[a].pb(b);
			 edge[b].pb(a);
	 } 
}
/*
void dfs(int node,int p)
{
		for(int u : edge[node]) 
		{
				if(u!=p)
				{
						dfs(u,node);
				}
		}
}
*/
///////////////////////////////////////////////////////////////////////////////////
int lis(std::vector<int> v)
{
	int n = v.size();
	if(n==0) return 0;
	std::vector<int> d1(n+1,inf);
	d1[0] = -inf;
	fp(i,0,n-1)
	{
		int j = upper_bound(d1.begin(),d1.end(),v[i]) - d1.begin();
        d1[j] = v[i];
	}
	fn(i,n,1)
		if(d1[i]!=inf) return i;
	return 1;
}
void solve()
{
	int n;
	cin>>n;
	int stock[n];
	for(int i = 0;i<n;i++) cin>>stock[i];
	int target;
	cin>>target;
	multiset<int> s;
	set<pair<int,int>> s1;
	for(int i = 0;i<n;i++) s.insert(stock[i]);
	for(int i = 0;i<n;i++)
	{
		s.erase(s.find(stock[i]));
		if(s.find(target-stock[i])!=s.end()) s1.insert({min(stock[i],target-stock[i]),max(stock[i],target-stock[i])});
	}
	d(s1.size())
}
int32_t main()
{
	IOS;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif
	int t=1;
	//cin>>t;
	fp(i,1,t)
	{
		//cout<<"Case "<<i<<": ";
		solve();
	}
}