#include <bits/stdc++.h>
#define ll long long
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
const int inf = 1000000;
#define maxn 200005
const int mod = 1000000007;
std::vector<int> v[maxn];int dis[101][101];
ll modexp(ll x,ll y) 
{ 
    ll res = 1;
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
ll invmod(int a)
{
    return modexp(a,mod-2);
}
void dfs(int node,int p,int cal,int dist)
{
    int u,i;
    dis[cal][node] = dist;
    for (i=0;i<v[node].size();i++)
    {
        u=v[node][i];
        if (u!=p)
        {
            dfs(u,node,cal,dist+1);
        }
    }
}
void solve()
{
    int n,a,b;
    cin>>n;
    int s[n+1];
    fpi(1,n,1) v[i].clear();
    fpi(1,n-1,1)
    {
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    fpi(1,n,1) cin>>s[i];
    fpi(1,n,1) dfs(i,-1,i,0);
    int ans=0;
    fpi(1,n,1)
    {
        fpj(1,n,1)
        {
            fpk(1,n,1)
            {
                if(i!=j && j!=k && k!=i && s[i] && s[j] && s[k] && dis[i][j]==dis[j][k] && dis[j][k]==dis[k][i] && dis[k][i]==dis[i][j]) ans++;
            }
        }
    }
    d(ans)
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
    return 0;
}