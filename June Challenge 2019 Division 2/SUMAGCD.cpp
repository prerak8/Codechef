#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
void pv(std::vector<int> v){cout<<v.size()<<endl;  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
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
#define pb push_back
#define mp make_pair
#define mod 1000000007
const int inf = (int)10e9 + 8;
#define maxn 100009
ll q[maxn],dpl[maxn],dpr[maxn];
int main()
{
    IOS;
    ll t,n,ans,k,t1,temp,a,d;
    cin>>t;std::vector<ll> v;
    fpk(1,t,1)
    {
        cin>>n;
        fpi(1,n,1) cin>>q[i];
        sort(q+1,q+n+1);
        v.clear(); v.push_back(-1);ans = 0;
        fpi(1,n,1) if((v.back())!=q[i]) v.push_back(q[i]);
        n = v.size()-1;
        if(n==1) d(2*v[1])
        else if(n==2) d(v[1] + v[2])
        else
        {
            dpl[0] = 0;dpr[n+1] = 0;
            fpi(1,n,1) dpl[i] = __gcd(dpl[i-1],v[i]);
            fni(n,1,1) dpr[i] = __gcd(dpr[i+1],v[i]);
            fpi(1,n,1) ans = max(ans,__gcd(dpl[i-1],dpr[i+1]) + v[i]);
            d(ans)
        }
    }
}