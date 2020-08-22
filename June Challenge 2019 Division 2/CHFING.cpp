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
ll mo(ll a,ll b)
{
    if(b==0) return 1%mod;
    if(b%2==1) return ((a%mod)*(mo(a,b-1)))%mod;
    else return (mo(a,b/2)*mo(a,b/2))%mod;
}
int main()
{
    IOS;
    ll t,n,ans,k,t1,temp,a,d;
    cin>>t;
    fpi(1,t,1)
    {
        cin>>n>>k;
        if((k-1)%(n-1)==0) t1 = (k-1)/(n-1); else t1 = (k-1)/(n-1) + 1;
        t1%=mod;
        a = (k-1)%mod;
        d = (n-1)%mod;
        ans = 1;
        ans*=t1;ans%=mod;
        temp = ((2*a)%mod - (d*(t1-1))%mod + mod)%mod;
        ans*=temp; ans%=mod;
        ans*=500000004;ans%=mod;
        d(ans)
    }
}