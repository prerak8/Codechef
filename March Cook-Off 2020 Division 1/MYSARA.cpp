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
const int inf = 1000000000;
#define maxn 300005
#define mod 1000000007
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
void add_edge(int u1,int v1)
{
    v[u1].pb(v1);
    v[v1].pb(u1);
}
int ask(int u,int v)
{
    d("? "<<u<<" "<<v)
    int t;
    cin>>t;
    return t;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve()
{
    int n;
    cin>>n;
    int b[n+1],bb[n+1][32];
    fpi(1,n,1) cin>>b[i];
    b[0]  = 0;
    fpi(0,n,1)
    {
        int temp = b[i];
        fpj(0,31,1)
        {
            bb[i][j] = temp%2;
            temp/=2;
        }
    }
    int ans = 1;
    fpi(1,n,1)
    {
        fpj(0,31,1)
        {
            if(bb[i-1][j]==0 && bb[i][j]==1)
            {
                ans%=mod;
            }
            else if(bb[i-1][j]==1 && bb[i][j]==1)
            {
                ans*=2;
                ans%=mod;
            }
            else if(bb[i-1][j]==0 && bb[i][j]==0)
            {
                ans%=mod;
            }
            else
            {
                d(0)
                return ;
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
}