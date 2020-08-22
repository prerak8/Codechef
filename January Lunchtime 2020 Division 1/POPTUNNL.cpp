#include <bits/stdc++.h>
using namespace std;
#define int long long 
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
void solve()
{
    int n,k;
    cin>>n>>k;
    char s1[n+1][n+1];
    fpi(1,n,1)
    {
        fpj(1,n,1)
        {
            cin>>s1[i][j];
        }
    }
    vector<int> v[n+1];
    fpi(1,n,1)
    {
        fpj(i+1,min(i+k,n),1)
        {
            if(s1[i][j]=='1')
            {
                v[i].pb(j);
            }
            if(s1[j][i]=='1')
            {
                v[j].pb(i);
            }
        }
    }
    int d[n+1];
    set<pair<int,int>> s;
    s.insert(mp(0LL,1LL));
    fpi(2,n,1) s.insert(mp((int)1000000,i));
    d[1] = 0;
    fpi(2,n,1) d[i] = (int)1000000;
    while(!s.empty())
    {
        int dist = (*(s.begin())).F;
        int temp = (*(s.begin())).S;
        if(temp==n)
        {
            if(dist>=1000000) d(-1)
            else d(dist)
            return ;
        }
        s.erase(s.begin());
        int  l = v[temp].size();
        fpi(0,l-1,1)
        {
            int u = v[temp][i];
            if(d[u]>dist+1)
            {
                s.erase(mp(d[u],u));
                d[u] = dist + 1;
                s.insert(mp(d[u],u));
            }
        }
    }
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