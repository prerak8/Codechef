#include <bits/stdc++.h>
#define int long long
using namespace std;
void pv(vector<int> v){cout<<v.size()<<' ';  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
void pa(int a[],int n,int p){for (int i = p; i < n+p; ++i){cout<<a[i]<<" ";}cout<<""<<endl;}
#define mem(a) memset(a,0,sizeof(a))
const double pi=3.141592653589793238;
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define d(x) cout<<x<<endl;
#define fni(x,y,z) for(int i=(int)x;i>=(int)y;i-=(int)z)
#define fnj(x,y,z) for(int j=(int)x;j>=(int)y;j-=(int)z)
#define fpi(x,y,z) for(int i=(int)x;i<=(int)y;i+=(int)z)  
#define fpj(x,y,z) for(int j=(int)x;j<=(int)y;j+=(int)z)
#define fpk(x,y,z) for(int k=(int)x;k<=(int)y;k+=(int)z)  
#define fnk(x,y,z) for(int k=(int)x;k>=(int)y;k-=(int)z)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define rev(a) reverse(a.begin(),a.en())
const int inf = (int)10e18;
#define maxn 1000005
const int mod = 1000000007; 
int modexp(int x,int y) 
{ 
	int res = 1;
	x = x % mod; 
	if (x == 0) return 0;
	while (y > 0) 
	{
		if (y & 1LL) 
			res = (res*x) % mod; 
		y = y>>1;
		x = (x*x) % mod;   
	} 
	return res; 
} 
int invmod(int n)
{
	return modexp(n,mod-2);
}
int cc(string s)
{
	int l = s.size();
	int temp = 1;
	int ans = 0;
	fpi(0,l-1,1)
	{
		ans+=temp*(s[i]-'0');
		temp*=2;
	}
	return ans;
}
int BinaryConcatenation(int X, int Y)
{
	string sx,sy;
	while(X)
	{
		if(X%2) sx+='1';
		else sx+='0';
		X/=2;
	}
	while(Y)
	{
		if(Y%2) sy+='1';
		else sy+='0';
		Y/=2;
	}
	string a = sx + sy;
	string b = sy + sx;
	return cc(a) - cc(b);
}
int len1(int a)
{
	int cou = 0;
	while(a)
	{
		cou++;
		a/=2;
	}
	return cou;
}
void solve()
{
	int n;
	cin>>n;
	int a[n+1];
	fpi(1,n,1) cin>>a[i];
	int mi[31]={0},mx[31]={0};
	fpi(0,30,1)
	{
		mi[i] = inf;
		mx[i] = 0;
	}
	std::vector<int> v;
	fpi(1,n,1)
	{
		int len = len1(a[i]);
		mx[len] = max(mx[len],a[i]);
		mi[len] = min(mi[len],a[i]);
	}
	fpi(0,30,1)
	{
		if(mx[i]==0) continue;
		v.pb(mx[i]);
		v.pb(mi[i]);
	}
	int l = v.size(),fans = 0;
	fpi(0,l-1,1)
	{
		fpj(i+1,l-1,1)
		{
			fans = max(fans,abs(BinaryConcatenation(v[i],v[j])));
		}
	}
	d(fans)
}   
int32_t main()
{
	IOS;
	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif
	int t=1;
	cin>>t;
	while(t--) solve();
	#ifndef LOCAL_DEFINE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
}