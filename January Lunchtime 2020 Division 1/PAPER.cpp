#include <bits/stdc++.h>
using namespace std;
#define int long long 
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
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define mod 1000000007
const int inf = 100000000000000000;
#define maxn 300009
pair<double,double> cal(pair<double,double> p,char a,double* u,double *d,double *l,double *r)
{
    double x = p.F,y = p.S;
    if(a=='U')
    {
        y = (*u) + (*u - y);
    }
    else if(a=='D')
    {
        y = (*d) - (y-*d);
    }
    else if(a=='L')
    {
        x = (*l )- (x-(*l));
    }
    else
    {
        x = (*r) + (*r-x);
    }
    pair<double,double> ans = {x,y};
    return ans;
}
void solve()
{
    int n,m,w,h;
    cin>>n>>m>>w>>h;
    string s;
    cin>>s;
    pair<double,double> po[m+1],temp;
    fpi(1,m,1) cin>>po[i].F>>po[i].S;
    double  l = 0,r = w,u = h,d = 0;int l1=0,d1 =0,r1 = 0,u1 = 0;
    double ans = 10e12;
    fpi(1,m,1)
    {
        fpj(1,m,1)
        {
            if(i!=j)
            {
                ans = min(ans,sqrt((po[i].F-po[j].F)*(po[i].F-po[j].F) + (po[i].S-po[j].S)*(po[i].S-po[j].S)));
            }
        }
    }
    fpi(0,n-1,1)
    {
        fpj(1,m,1)
        {
            temp = cal(po[j],s[i],&u,&d,&l,&r);
            ans = min(ans,sqrt((temp.F-po[j].F)*(temp.F-po[j].F) + (temp.S-po[j].S)*(temp.S-po[j].S)));
            po[j] = temp;
        }
        if(s[i]=='U') u = u + (u - d);
        if(s[i]=='D') d = d - (u-d);
        if(s[i]=='L') l = l - (r-l);
        if(s[i]=='R') r = r + (r-l);
        // d(l<<" "<<r<<" "<<d<<" "<<u)
        // fpj(1,m,1) d(po[j].F<<" "<<po[j].S)
    }
    fpi(1,m,1)
    {
        fpj(1,m,1)
        {
            if(i!=j)
            {
                ans = min(ans,sqrt((po[i].F-po[j].F)*(po[i].F-po[j].F) + (po[i].S-po[j].S)*(po[i].S-po[j].S)));
            }
        }
    }
    // if(l1>0 || r1>=2)
    // {
    //     fpi(1,m,1) if(po[i].F-l)ans = min(ans,(po[i].F-l)*2); 
    // }
    // if(r1>0 || l1>=2)
    // {
    //     fpi(1,m,1) if(r -po[i].F) ans = min(ans,(r -po[i].F)*2);
    // }
    // if(u1>0 || d1>=2)
    // {
    //     fpi(1,m,1) if(u -po[i].S) ans = min(ans,(u -po[i].S)*2);
    // }
    // if(d1>0 || u1>=2)
    // {
    //     fpi(1,m,1) if(po[i].S-d) ans = min(ans,(po[i].S-d)*2);
    // }
    cout << std::setprecision(12) << ans << '\n';
}
int32_t main()
{
    IOS;
    int t = 1;
    cin>>t;
    while(t--) solve();
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}

