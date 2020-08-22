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
#define mod 1000000007
void print(int * ans,int n,int f)
{
    if(f)
    {
        cout<<"YES ";
        fpi(1,n,1) cout<<ans[i]<<" ";
        cout<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
void solve()
{
    int n,p;
    cin>>n>>p;
    pair<int,int> d[n+1];int ans[n+1]={0};
    fpi(1,n,1) {cin>>d[i].F;d[i].S = i;}
    fpi(1,n,1)
    {
        if(d[i].F>p)
        {
            ans[i]++;
            print(ans,n,1);
            return;
        }
        else if(p%d[i].F)
        {
            ans[i] = p/d[i].F + 1;
            print(ans,n,1);
            return;
        }
    }
    if(n==1) {print(ans,n,0);return;}
    sort(d+1,d+n+1);
    fni(n-1,1,1)
    {
        if(d[i].F==1) break;
        if(d[i+1].F%d[i].F)
        {
            ans[d[i+1].S] = p/d[i+1].F - 1;
            ans[d[i].S] = d[i+1].F/d[i].F + 1;
            print(ans,n,1);
            return ;
        }
    }
    print(ans,n,0);
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