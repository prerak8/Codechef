#include <bits/stdc++.h>
#define int long long
using namespace std;
void pv(vector<int> v){cout<<v.size()<<endl;  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
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
const int inf = 2000000;
#define maxn 200005
#define mod (long long int)10e9+7
void solve()
{
    int a,m;
    cin>>a>>m;
    int temp = sqrt(m),ans;
    std::vector<int> v;
    fpi(1,temp,1)
    {
        if(m%i==0)
        {
            if(m/i==i)
            {
                ans = m/i - 1;
                if(ans%a==0)
                {
                    ans/=a;
                    ans*=i;
                    if(ans) v.pb(ans);
                }
            }
            else
            {
                ans = m/i - 1;
                if(ans%a==0)
                {
                    ans/=a;
                    ans*=i;
                    if(ans) v.pb(ans);
                }
                i = m/i;
                ans = m/i - 1;
                if(ans%a==0)
                {
                    ans/=a;
                    ans*=i;
                    if(ans) v.pb(ans);
                }
                i = m/i;
            }
        }
    } 
    sort(v.begin(),v.end());
    pv(v);
}
int32_t main(){
    IOS;
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    int n=1;
    cin>>n;
    while(n--){
        solve();
    }
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}