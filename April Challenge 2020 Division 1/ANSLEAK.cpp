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
const int inf = 100000000000000000;
#define maxn 300005
#define mod 998244353
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
int ask(int u)
{
    d("1 "<<u)
    int t;
    cin>>t;
    //if(t==-1) while(1);
    return t;
}
int ask1(int u,int v)
{
    d("2 "<<u<<" "<<v)
    int t;
    cin>>t;
    //if(t==-1) while(1);
    return t;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
int c[501][5001],n,m,k,mans = -1;
vector<int> ans,tans,numbers;
void anscheck()
{
    int mi = INT_MAX;
    fpi(1,k,1)
    {
        int cou = 0;
        fpj(1,n,1)
        {
            if(tans[j-1]==c[j][i]) cou++;
        }
        mi = min(mi,cou);
    }
    if(mi>mans) {ans = tans;mans = mi;}
}
void cc(int a,int number,int randmization)
{
    tans.clear();
    int is[k+1];
    mem(is);
    fpi(1,k,1) if(c[number][i]==a) is[i]++;
    fpi(1,1000,1)
    {
        if(randmization==0)  break;
        swap(numbers[rand()%n],numbers[rand()%n]);
    }
    fpk(0,n-1,1)
    {
        int i = numbers[k];
        if(i==number) {tans.pb(a); continue;}
        int tt[m+1]={0};
        fpj(1,k,1) if(is[j]==0) tt[c[i][j]]++;
        int mx = max_element(tt+1,tt+m+1)-tt;
        if(tt[mx]==0)
        {
            mem(is);
            fpj(1,k,1) if(is[j]==0) tt[c[i][j]]++;
            mx = max_element(tt+1,tt+m+1)-tt;
        }
        tans.pb(mx);
        fpj(1,k,1) if(c[i][j]==mx) is[j]=1;
    }
    anscheck();
}
void solve()
{
    numbers.clear();
    mans = -1;
    cin>>n>>m>>k;
    fpi(1,n,1) numbers.pb(i);
    fpi(1,n,1) fpj(1,k,1) cin>>c[i][j];
    int cou = 0;
    fpi(1,m,1) fpj(1,n,1) {cou++; if(cou>100) break;cc(i,j,0);}
    cou = 0;
    fpi(1,m,1) fpj(1,n,1) {cou++; if(cou>100) break;cc(i,j,1);}
    pv(ans);
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