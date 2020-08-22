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
vector<pair<int,pair<int,int>>> v;
void build()
{
	int n = 9001;
	int fin[9001];
	fin[1] = 1;
	fpi(2,9000,1) fin[i] = 1 + fin[i - fin[fin[i-1]]];
	v.pb({0,{0,0}});
	int cou = 0,id = 0;
	fpi(1,9000,1)
	{
		fpj(1,fin[i],1)
		{
			cou++;
			id+=i;
			int temp = v.back().S.F + (((i*(cou%mod))%mod)*cou)%mod;
			temp%=mod;
			v.pb({id,{temp,cou}});
		}
	}
	//d(id)
}

int find(int a)
{
	int l = 0,r = v.size()-1;
	int ans;
	while(l<=r)
	{
		int mid = (l+r)/2;
		if(v[mid].F==a)
		{
			ans = mid;
			//d("worked "<<a)
			return v[mid].S.F;
			break;
		}
		else if(v[mid].F>a)
		{
			ans = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	int tt = v[ans].S.S;
	//d(a<<" ok "<<v[ans].F<<" "<<tt)
	tt = (tt*tt)%mod;
	return (v[ans].S.F - (((v[ans].F-a)%mod)*(tt))%mod + mod)%mod;
}
void solve()
{
	int l,r;
	cin>>l>>r;
	//d(l-1<<" "<<find(l-1))
	//d(r<<" "<<find(r))
	d((find(r) - find(l-1) + mod)%mod)
}   
int32_t main()
{
	IOS;
	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif
	// int fin[101];
	// fin[1] = 1;
	// fpi(2,100,1) fin[i] = 1 + fin[i - fin[fin[i-1]]];
	// int co = 0,pp = 1;
	// std::vector<int> v1;
	// v1.pb(0);
	// fpi(1,5,1)
	// {
	// 	fpj(1,fin[i],1)
	// 	{
	// 		co++;
	// 		fpk(1,i,1)
	// 		{
	// 			d(co<<" "<<fin[pp++])
	// 		}
	// 	}
	// }
	// d(v1[100])
	build();
	// fpi(0,25,1)
	// {
	// 	d(v[i].F<<" "<<v[i].S.F<<" "<<v[i].S.S)
	// }
	int t=1;
	cin>>t;
	while(t--) solve();
	#ifndef LOCAL_DEFINE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
}