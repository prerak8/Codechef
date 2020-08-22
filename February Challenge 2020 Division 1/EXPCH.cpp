#include <bits/stdc++.h>
#define int long long
using namespace std;
void pv(vector<int> v){  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
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
#define rev(a) reverse(a.begin(),a.end())
const int inf = 100000000000;
#define maxn 200005
const int mod = 1000000007;
int modexp(int x,int y) 
{ 
    int res = 1;
    x = x % mod; 
    while (y > 0) 
    {
        if (y & 1LL) 
            res = (res*x) % mod; 
        y = y>>1;
        x = (x*x) % mod;   
    } 
    return res; 
} 
int invmod(int a)
{
    return modexp(a,mod-2);
}
int cc(int a)
{
    if(a>=0) return 0;
    else return (1-a)/2;
}
void solve()
{
    int n,ans=0,tempans=0,tot=0;
    cin>>n;
    string s;
    int mi = INT_MAX,dp[n+1],odd[n+1];
    cin>>s;
    s = "0" + s;
    dp[0] = 0;
    fpi(1,n,1) if(s[i]=='(') dp[i] = dp[i-1] + 1; else if(s[i]==')') dp[i] = dp[i-1] - 1; else dp[i] = dp[i-1];
    fpi(1,n,1)
    {
        int mi = n+5;
        fpj(i,n,1)
        {
            mi = min(mi,dp[j]-dp[i-1]);
            //if(cc(mi)) d(i<<" "<<j<<" "<<cc(mi))
            ans+=cc(mi);
            if(ans>=mod) ans-=mod;
            tot++;
            if(tot>=mod) tot-=mod;
        }
    }
    //d(ans<<" "<<tot) 
    ans = (ans*invmod(tot))%mod;
    d(ans)
}
int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}