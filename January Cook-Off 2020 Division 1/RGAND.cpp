#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>
#include <string.h>
#include <queue>
#include <map>
#define int long long 
using namespace std;
void pv(std::vector<int> v){  for (int i = 0; i < (int)v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
void pa(int a[],int n,int p){for (int i = p; i < n+p; ++i){cout<<a[i]<<" ";}cout<<""<<endl;}
#define mem(a) memset(a,0,sizeof(a))
const double pi=3.141592653589793238;
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define d(x) cout<<x<<endl;
#define fni(x,y,z) for(int i=x;i>=y;i-=z)
#define fnj(x,y,z) for(int j=x;j>=y;j-=z)
#define fpi(x,y,z) for(int i=x;i<=y;i+=z)   
#define fpj(x,y,z) for(int j=x;j<=y;j+=z)
#define fpk(x,y,z) for(int k=x;k<=y;k+=z)   
#define fnk(x,y,z) for(int k=x;k>=y;j-=z)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define mod 1000000007
const int inf = 100000000000000000;
#define maxn 300009
// int a[maxn],dp[maxn];
// vector<int> v[maxn];
// void dfs(int node,int p)
// {
//     int u,i;
//     if(v[node].size()==1) {dp[node] = 1;return ;}
//     else dp[node] = 0LL;
//     for (i=0;i<v[node].size();i++)
//     {
//         u=v[node][i];
//         if (u!=p)
//         {
//             dfs(u,node);
//             dp[node]+=dp[u];
//         }
//     }
// }
// void solve()
// {
// 	int n,a1,b,root,leaf = 0;
//     cin>>n;
//     fpi(1,n,1) {cin>>a[i];v[i].clear();}
//     fpi(1,n-1,1)
//     {
//         cin>>a1>>b;
//         v[a1].pb(b);
//         v[b].pb(a1);
//     }
//     fpi(1,n,1) if(v[i].size()>1) {dfs(i,-1);root = i;break;}
//     fpi(1,n,1) if(v[i].size()==1) leaf++;
//     int tot = 0;
//     fpi(0,(int)v[root].size()-1,1)
//     {
//         tot+=dp[v[root][i]];
//     }
//     dp[root] = 0;
//     fpi(0,(int)v[root].size()-1,1)
//     {
//         tot-=dp[v[root][i]];
//         dp[root] += dp[v[root][i]]*tot;
//     }
//     fpi(1,n,1) {if(i!=root) dp[i] = dp[i]*(leaf-dp[i]);}
//     sort(dp+1,dp+n+1);
//     sort(a+1,a+n+1);
//     int ans = 0;
//     fpi(1,n,1)
//     {
//         ans+=(a[i]*dp[i])%mod;
//         ans%=mod;
//     }
//     d(ans)
// }
void solve()
{
    int l,r,l1;
    cin>>l>>r;
    int a[65];
    l1 = l;
    fpi(0,64,1)
    {
        a[i] = l1%2;
        l1/=2;
    }
    int ans = 0,temp = 1,tans;
    fpi(0,64,1)
    {
        if(a[i]==0) {temp*=2;continue;}
        tans = min(r,l - l%(2*temp) + 2*temp-1)-l+1;
        tans%=mod;
        tans*=(temp%mod);
        tans%=mod;
        ans+=tans;
        ans%=mod;
        temp*=2;
    }
    d(ans)
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
