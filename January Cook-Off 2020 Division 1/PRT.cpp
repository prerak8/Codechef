#include <bits/stdc++.h>
#define ll long long 
using namespace std;
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fpi(x,y,z) for(int i=x;i<=y;i+=z)   
#define mod 1000000007
#define pb push_back
#define maxn 300009
int a[maxn],dp[maxn],leaf;
ll dp1[maxn];
vector<int> v[maxn];
void dfs(int node,int p)
{
    int u,i;ll tot;
    if(v[node].size()==1) {dp[node] = 1;}
    else dp[node] = 0LL;
    for (i=0;i<v[node].size();i++)
    {
        u=v[node][i];
        if (u!=p)
        {
            dfs(u,node);
            dp[node]+=dp[u];
        }
    }
    tot = dp[node];
    dp1[node] = tot*(leaf-tot);
    for (i=0;i<v[node].size();i++)
    {
        u=v[node][i];
        if (u!=p)
        {
            tot-=dp[u];
            dp1[node]+=dp[u]*tot;
        }
    }
}
void solve()
{
	int n,a1,b,root = 1;
    leaf = 0;
    cin>>n;
    fpi(1,n,1) {cin>>a[i];v[i].clear();}
    fpi(1,n-1,1)
    {
        cin>>a1>>b;
        v[a1].pb(b);
        v[b].pb(a1);
    }
    if(n==1)
    {
        cout<<0<<'\n';
        return ;
    }
    else if(n==2)
    {
        cout<<((ll)a[1]+a[2])%mod<<'\n';
        return;
    }
    fpi(1,n,1) if(v[i].size()==1) leaf++;
    fpi(1,n,1) if(v[i].size()>1) {dfs(i,-1);root = i;break;}
    sort(dp1+1,dp1+n+1);
    sort(a+1,a+n+1);
    ll ans = 0;
    fpi(1,n,1)
    {
        ans+=(a[i]*(dp1[i]%mod))%mod;
        ans%=mod;
    }
    cout<<ans<<'\n';
}
int32_t main()
{
    IOS;
    int t = 1;
    cin>>t;
    while(t--) solve();
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
} 