#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void pv(vector<int> v){  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
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
#define fnk(x,y,z) for(int k=x;k>=y;k-=z)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define rev(a) reverse(a.begin(),a.end())
const int inf = 1000000;
#define maxn 100005
#define mod (int)10e9+7
void solve(){
    ll n,m,q,a,b,ro=0,co=0,re=0,ce=0;
    cin>>n>>m>>q;
    ll r[n+1]={0},c[m+1]={0};
    fpi(1,q,1)
    {
        cin>>a>>b;
        r[a]++;
        c[b]++;
    }
    fpi(1,n,1) if(r[i]%2) ro++; else re++;
    fpi(1,m,1) if(c[i]%2) co++; else ce++;
    d(ro*ce + re*co)
}
int main(){
    IOS;
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}