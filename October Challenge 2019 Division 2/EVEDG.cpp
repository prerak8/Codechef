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
//#define mp make_pair
#define F first
#define S second
#define rev(a) reverse(a.begin(),a.end())
const int inf = 1000000;
#define maxn 750000
#define mod (int)10e9+7
void solve()
{
    int m,n,u,v;
    cin>>n>>m;
    int dp[n+1]={0};
    fpi(1,m,1)
    {
        cin>>u>>v;
        dp[u]++;
        dp[v]++;
    }
    if(m%2==0)
    {
        d(1)
        fpi(1,n,1) cout<<1<<" ";
        cout<<endl;
    }
    else
    {
        fpi(1,n,1)
        if(dp[i]%2)
        {
            d(2)
            fpj(1,n,1) if(j==i) cout<<2<<" "; else cout<<1<<" ";
            cout<<endl;
            return;
        }
        d(3)
        fpi(1,n,1)
        {
            if(i==u) cout<<1<<" ";
            else if(i==v) cout<<2<<" ";
            else cout<<3<<" ";
        }
    }
}
int main(){
    IOS;
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    int t;
    cin>>t;
    while(t--) solve();
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}