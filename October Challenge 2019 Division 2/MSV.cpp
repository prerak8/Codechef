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
int mp[1000000+1],ans[1000000+1];
void solve()
{
    int n,tt;
    fpi(1,1000000,1) mp[i] = 0,ans[i] = 0;
    cin>>n;
    int q[n+1];
    fpi(1,n,1) {cin>>q[i];mp[q[i]] = i;}
    fpi(1,n,1)
    {
        fpj(1,sqrt(q[i]),1)
        {
            if(q[i]%j==0)
            {
                if(j*j==q[i])
                {
                    if(mp[j]>i) ans[j]++;
                }
                else
                {
                    if(mp[j]>i) ans[j]++;
                    if(mp[q[i]/j]>i) ans[q[i]/j]++;
                }
            }
        }
    }
    d(*max_element(ans,ans+1000001))
}
int main(){
    IOS;
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    ans[0] = 0;
    int t;
    cin>>t;
    while(t--) solve();
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}