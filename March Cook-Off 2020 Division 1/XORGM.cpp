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
std::vector<int> v[maxn];
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
void dfs(int node,int p)
{
    int u,i;
    for (i=0;i<v[node].size();i++)
    {
        u=v[node][i];
        if (u!=p)
        {
            dfs(u,node);
        }
    }
}
void solve()
{
    int n,c=0;
    cin>>n;
    int a[n+1],b[n+1];
    fpi(1,n,1) cin>>a[i];
    fpi(1,n,1) cin>>b[i];
    fpi(1,n,1) {c = c^a[i];c = c^b[i];}
    int ans1[n+1],ans2[n+1];
    fpi(1,n,1) {ans1[i] = a[i]^c;ans2[i] = ans1[i];}
    sort(ans2+1,ans2+n+1);
    sort(b+1,b+n+1);
    fpi(1,n,1) if(b[i]!=ans2[i]) {d(-1) return;}
    fpi(1,n,1) cout<<ans1[i]<<" ";
    cout<<endl;
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
    return 0;
}