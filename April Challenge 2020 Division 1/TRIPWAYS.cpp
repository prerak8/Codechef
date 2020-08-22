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
const int inf = (int)(10e18);
#define maxn 100005
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
std::vector<int> v[maxn];
int dp[4001][2001];
void solve()
{
    int n,m,q;
    cin>>n>>m>>q;
    int a[n+1];
    fpi(1,n,1) cin>>a[i];
    fpi(1,m,1)
    {
        int a,b;
        cin>>a>>b;
        if(a<b) swap(a,b);
        v[a].pb(b);
    }
    fpi(1,n,1)
    {
        if(i==1)
        {
            fpj(0,2000,1)
            {
                dp[1][j] = modexp(a[1],j);
            }
        }
        else
        {
            int l = v[i].size();
            fpj(0,l-1,1)
            {
                int u = v[i][j];
                int temp[2001];
                temp[0] = 0;
                fpj(1,2000,1) temp[j] = ((temp[j-1]*a[i])%mod + dp[u][j-1])%mod;
                fpj(1,2000,1) {dp[i][j]+=temp[j];dp[i][j]%=mod;}
            }
        }
    }
    fpi(1,q,1)
    {
        int a;
        cin>>a;
        d(dp[n][a])
    }
}   
int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    int t = 1;
    //cin>>t;
    while(t--) solve();
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}