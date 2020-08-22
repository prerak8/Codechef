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
#define mp make_pair
#define F first
#define S second
#define rev(a) reverse(a.begin(),a.end())
const int inf = 1000000;
#define maxn 750000
//#define mod (long long int)10e9+7
long long int fact[200005],ifact[200005],mod = 1000000007;
long long power(long long x, unsigned long long int y, unsigned long long int m)
{ 
    if (y == 0) 
        return 1; 
    long long int p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 
long long int modInverse(long long int a,long long int m) 
{ 
    long long int g = __gcd(a, m); 
    if (g != 1) return 1;
    else
    { 
        return power(a, m-2, m); 
    } 
}
void solve()
{
    long long n,a0 = 0,a1 = 0,b0 = 0,b1 = 0,ans = 0,temp;
    string a,b;
    cin>>n;
    cin>>a;
    cin>>b;
    fpi(0,n-1,1)
    {
        if(a[i]=='0') a0++;
        else a1++;
        if(b[i]=='0') b0++;
        else b1++;
    }
    fpi(0,n,1)
    {
        if((a0+b0-i>=0 && (a0+b0-i)%2==0) && (a0-b0+i>=0 && (a0-b0+i)%2==0) && (i-a0+b0>=0 && (i-a0+b0)%2==0) && (a0+b0+i<=2*n))
        {
            temp = (((fact[n]*ifact[i])%mod)*ifact[n-i])%mod;
            ans+=temp;
            ans%=mod;
        }
    }
    d(ans)
}
int main(){
    IOS;
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    fact[0] = 1;ifact[0] = 1;
    fpi(1,200005,1)
    {
        fact[i] = (fact[i-1]*i)%mod;
        ifact[i] = (ifact[i-1]*modInverse(i,mod))%mod;
    }
    int n;
    cin>>n;
    while(n--){
        solve();
    }
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}
