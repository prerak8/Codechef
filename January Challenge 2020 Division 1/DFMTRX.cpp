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
const int inf = 1000000;
#define maxn 1000005
#define mod (int)10e9+7
int q[2005][2005];
void cc(int n)
{
    if(n==1)
    {
        q[1][1] = 1;
        return ;
    }
    cc(n/2);
    fpi(n/2+1,n,1)
    {
        fpj(n/2+1,n,1)
        {
            q[i][j] = q[i-n/2][j-n/2];
        }
    }
    int x=n/2+1,y=1,temp,x1,y1;
    fpi(n,n+n/2-1,1)
    {
        x1 = x;y1 = y;
        fpj(1,n/2,1)
        {
            q[x1][y1] = i;
            if(x1==n) x1 = n/2+1; else x1++;
            if(y1==n/2) y1 = 1; else y1++;
        }
        y++;
    }
    x = 1;y = n/2 + 1;
    fpi(n+n/2,2*n-1,1)
    {
        x1 = x;y1 = y;
        fpj(1,n/2,1)
        {
            q[x1][y1] = i;
            if(y1==n) y1 = n/2+1; else y1++;
            if(x1==n/2) x1 = 1; else x1++;
        }
        y++;
    }
}
void solve()
{
    int n;
    cin>>n;
    int temp = 1;
    fpi(1,n,1)
    {
        if(n==temp)
        {
            cc(n);
            d("Hooray")
            fpj(1,n,1)
            {
                fpk(1,n,1)
                {
                    cout<<q[j][k]<<"  ";
                }
                cout<<endl;
            }
            return ;
        }
        temp*=2;
    }
    d("Boo")
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