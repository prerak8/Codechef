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
const int inf = (int)(10e18);
#define maxn 100005
const int mod = 1000000007; 
int modexp(int x,int y) 
{ 
    int res = 1;
    x = x % mod; 
    if (x == 0) return 0;
    while (y > 0) 
    {
        if (y & 1LL) 
            res = (res*x) % mod; 
        y = y>>1;
        x = (x*x) % mod;   
    } 
    return res; 
} 
int invmod(int n)
{
    return modexp(n,mod-2);
}
int inv6;
inline int pp(int a)
{
    int ans = a%mod;
    ans*=(a+1)%mod;
    ans%=mod;
    ans*=(2*a+1)%mod;
    ans%=mod;
    ans*=inv6;
    ans%=mod;
    return ans;
}
int sum(int l,int r)
{
    if(l>r) return 0;
    return (pp(r) - pp(l-1) + mod)%mod;
}
int sqrt1(int a)
{
    int l = 0,r = 1000000000,ans;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(mid*mid==a) return mid;
        else if(mid*mid<a) {ans = mid;l = mid + 1;}
        else r = mid -1;
    }
    return ans;
}
std::vector<int> v,v1;
void build()
{
    for(int i = 2;i<=1000000;i++)
    {
        int temp = i*i;
        for(int j = 3;j<=64;j++)
        {
            if(temp>inf/i) break;
            temp*=i;
            int t1 = sqrt1(i);
            if(j%2 && t1*t1!=i) v1.pb(temp);
        }
    }
    sort(v1.begin(),v1.end());
    int l = v1.size();
    v.pb(v1[0]);
    for(int i = 1;i< l;i++) if(v1[i]!=v1[i-1]) v.pb(v1[i]);
}
void solve()
{
    int n;
    cin>>n;
    int ans = 0,i = 1,cou=1;
    while(1)
    {
        int t1 = sqrt1(n/(i+1))+1;
        int t2 = sqrt1(n/i);
        if(t1>=t2) break;
        ans+=((cou%mod)*sum(t1,t2))%mod;
        i++;
        cou++;
    }
    int t1 = sqrt1(n/i);
    fpi(1,t1,1)
    {
        int t2 = i*i;
        ans+=((n/t2)*t2)%mod;
        ans%=mod;
    }
    for(int j : v)
    {
        if(j>n) break;
        ans+=((n/j)*j)%mod;
        ans%=mod;
    }
    d(ans)
}   
int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    inv6 = invmod(6);
    build();
    int t = 1;
    cin>>t;
    while(t--) solve();
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}