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
const int inf = (int)10e12;
#define maxn 100005
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
int n;
string s,s1;
int dpn[500002],weigth[26],dpw[500002];
std::vector<int> kmp,v[500002];

int getdpn(int a,int size)
{
    int temp = (dpn[a] - dpn[a+size] + mod)%mod;
    int den = modexp(27,n-a-size);
    den=invmod(den);
    return (temp*den)%mod;
}

int getdpw(int a,int size)
{
    return (dpw[a] - dpw[a+size] + mod)%mod;
}

bool check(int start,int blocksize,int tot)
{
    int blocknum = tot/blocksize;
    int num = modexp(27,tot);
    num = (num - 1 + mod)%mod;
    int den = modexp(27,blocksize);
    den = (den - 1 + mod)%mod;
    int final = (num*invmod(den))%mod;
    final*=getdpn(start,blocksize);
    final%=mod;
    if(final==getdpn(start,tot)) return 1;
    else return 0;
}

bool finalcheck(int start,int blocksize,int tot)
{
    int rem = tot%blocksize;
    int reptot = tot - rem;
    if(check(start,blocksize,reptot)&&getdpn(start,rem)==getdpn(start+tot-rem,rem)) return 1;
    else return 0;
}

int binarysearch(int start,int blocksize)
{
    int l = blocksize;
    int r = n - start;
    int ans = blocksize;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(finalcheck(start,blocksize,mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}
void build()
{
    n = s.size();
    s1 = s;
    rev(s1);
    fpi(0,n,1) v[i].clear();

    dpn[n] = 0;
    int temp = 1;
    fni(n-1,0,1)
    {
        dpn[i] = dpn[i+1] + (temp*(s[i]-'a'+1))%mod;
        dpn[i]%=mod;
        temp*=27;
        temp%=mod;
    }

    dpw[n] = 0;
    fni(n-1,0,1)
    {
        dpw[i] = dpw[i+1] + weigth[s[i]-'a']%mod;
        dpw[i]%=mod;
    }

    kmp.resize(n);
    kmp[0] = 0;
    fpi(1,n-1,1)
    {
        int temp = kmp[i-1];
        while(temp>0 && s1[temp]!=s1[i]) temp = kmp[temp-1];
        if(s1[temp]==s1[i]) temp++;
        kmp[i] = temp;
    }

    fpi(0,n-1,1)
    {
        int temp = kmp[i];
        while(temp>0)
        {
            v[n-1-i].pb(temp);
            temp = kmp[temp-1];
        }
    }
    int fans = 0;
    fpi(0,n-1,1)
    {
        int totsize = n - i;
        fpj(1,totsize,1)
        {
            int tans = binarysearch(i,j);
            int blockval = getdpw(i,j);
            ///d(i<<" "<<j<<" "<<tans<<" "<<(tans-j+1)<<" "<<blockval<<" "<<(blockval)*(tans-j+1))
            fans+=((blockval)*(tans-j+1))%mod;
            fans%=mod;
        }
    }
    //d(fans)
    // fpi(0,n-1,1)
    // {
    //     int hi = (i+1)*(n-i);
    //     hi%=mod;
    //     hi*=weigth[s[i]-'a']%mod;
    //     hi%=mod;
    //     fans+=hi;
    //     fans%=mod;
    // }
    int finalden = (n*(n+1))/2;
    finalden%=mod;
    fans*=invmod(finalden);
    fans%=mod;
    d(fans)
}
void solve()
{
    cin>>s;
    fpi(0,25,1) {cin>>weigth[i];weigth[i]%=mod;}
    build();
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

// unordered_map<int,int> um;
//         for(int value : v[i])
//         {
//             int repsize = totsize - value;
//             fpj(1,sqrt(repsize),1)
//             {
//                 if(repsize%j==0)
//                 {
//                     int blocksize = j,t2 = repsize/j;
//                     if(blocksize>=value && check(i,blocksize,repsize))
//                     {
//                         if(um[blocksize]==0)
//                         {
//                             um[blocksize]=1;
//                             int left = getdpw(i,blocksize);
//                             int right = totsize - blocksize;
//                             fans+=(left*right)%mod;
//                             fans%=mod;
//                         }
//                     }
//                     swap(t2,blocksize);
//                     if(blocksize>=value && check(i,blocksize,repsize))
//                     {
//                         if(um[blocksize]==0)
//                         {
//                             um[blocksize]=1;
//                             int left = getdpw(i,blocksize);
//                             int right = totsize - blocksize;
//                             fans+=(left*right)%mod;
//                             fans%=mod;
//                         }
//                     }
//                 }
//             }
//         }