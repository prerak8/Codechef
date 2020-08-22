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
#define rev(a) reverse(a.begin(),a.en())
const int inf = 100000000000;
#define maxn 200005
const int mod = 998244353; 
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
int start[1000005],en[1000005],invmod2;
string s;
void build()
{
    stack<int> st;
    int l = s.size();
    fpi(0,l-1,1)
    {
        if(s[i]=='(')
        {
            st.push(i);
        }
        else if(s[i]==')')
        {
            start[st.top()] = i;
            en[i] = st.top();
            st.pop();
        }
        else if(s[i]=='#')
        {
            start[i] = i;
            en[i] = i;
        }
    }
}
int cc(int l,int r,char c)
{
    int ans = 0;
    if(c=='&')
    {
        ans+=(l*r)%mod;
        ans%=mod;
        ans+=(l*((1-r+mod)%mod))%mod;
        ans%=mod;
        ans+=(r*((1-l+mod)%mod))%mod;
        ans%=mod;
    }
    else if(c=='^')
    {
        ans+=(l*r)%mod;
        ans%=mod;
        ans+=(((1-l+mod)%mod)*((1-r+mod)%mod))%mod;
        ans%=mod;
    }
    else
    {
        ans+=(l*r)%mod;
        ans%=mod;
    }
    return ans;
}
int cal(int l,int r)
{
    if(l==r) return invmod2;
    else
    {
        int al = cal(l+1,start[l+1]);
        int ar = cal(en[r-1],r-1);
        return cc(al,ar,s[start[l+1]+1]);
    }
}
void solve()
{
    invmod2 = invmod(2);
    cin>>s;
    build();
    int p0 = cal(0,s.size()-1);
    int p1 = (1-p0+mod)%mod;
    cout<<(p0*p0)%mod<<" ";
    cout<<(p1*p1)%mod<<" ";
    cout<<(p1*p0)%mod<<" ";
    cout<<(p1*p0)%mod<<'\n';
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