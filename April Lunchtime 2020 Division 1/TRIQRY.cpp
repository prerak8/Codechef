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
#define maxn 1000005
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
std::vector<int> s[maxn],e[maxn];pair<int,int> a[maxn];
int block = 2000;
bool cc(pair<pair<int,int>,int> p1,pair<pair<int,int>,int> p2)
{
    if(p1.F.F/block==p2.F.F/block) return p1.F.S<p2.F.S;
    else return p1.F.F/block<p2.F.F/block;
}
int curl = -1,curr = -1,tot = 0;
void add1(int a)
{
    for(auto i : s[a])
    {
        if(i>=curl) {tot++;}
    }
}
void add2(int a)
{
    for(auto i : e[a])
    {
        if(i<=curr) {tot++;}
    }
}
void sub1(int b)
{
    for(auto i : e[b])
    {
        if(i<=curr) {tot--;}
    }
}
void sub2(int b)
{
    for(auto i : s[b])
    {
        if(i>=curl) {tot--;}
    }
}
void solve()
{
    curl = -1;
    curr = -1;
    tot = 0;
    int n,q;
    cin>>n>>q;
    fpi(1,n,1)
    {
        cin>>a[i].F>>a[i].S;
        if(a[i].F+a[i].S<=1000000 && a[i].F-a[i].S>=0)
        {
            s[a[i].F+a[i].S].pb(a[i].F-a[i].S);
            e[a[i].F-a[i].S].pb(a[i].F+a[i].S); 
        }
    }
    pair<pair<int,int>,int> query[q+1];
    int mi = INT_MAX,mx = 0;
    fpi(1,q,1)
    {
        cin>>query[i].F.F>>query[i].F.S;
        query[i].S = i;
    }
    sort(query+1,query + q+1,cc);
    int ans[q+1];
    fpi(1,q,1)
    {
        int l = query[i].F.F,r = query[i].F.S;
        // d(l<<" "<<r)
        while(curr<r) add1(++curr);
        while(curr>r) sub2(curr--);
        while(curl<l) sub1(curl++);
        while(curl>l) add2(--curl);
        ans[query[i].S] = tot;
    }
    fpi(1,q,1) cout<<ans[i]<<" ";
    fpi(1,n,1)
    {
        if(a[i].F+a[i].S<=1000000 && a[i].F-a[i].S>=0)
        {
            s[a[i].F+a[i].S].pop_back();
            e[a[i].F-a[i].S].pop_back(); 
        }
    }
    cout<<"\n";
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