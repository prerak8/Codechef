#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void pv(vector<int> v){  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
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
#define fnk(x,y,z) for(int k=x;k>=y;k-=z)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define rev(a) reverse(a.begin(),a.end())
const int inf = 1000000;
#define maxn 500005
#define mod (int)10e9+7
int q[101][101][101];
bool cc(pair<int,int> i1,pair<int,int> i2)
{
    return (i1.S<i2.S);
}
void solve()
{
    int n,l;
    cin>>n;
    string s;
    fpi(1,n*n,1)
    {
        cin>>s;
        l = s.size();
        fpj(0,l-1,1)
        {
            if(i%n==0)
            {
                q[j+1][n][(i-n)/n+1] = s[j] - '0';
                //d(j+1<<" "<<n<<" "<<(i-n)/n+1)
            }
            else
            {
                q[j+1][i%n][(i-(i%n))/n+1] = s[j] - '0';
                //d(j+1<<" "<<i%n<<" "<<(i-(i%n))/n+1)
            }
        }
    }
    pair<int,int> x[n+1],y[n+1],z[n+1];
    fpi(1,n,1) x[i].S = 0,y[i].S = 0,z[i].S = 0,x[i].F = i,y[i].F = i,z[i].F = i;
    fpi(1,n,1)
    {
        fpj(1,n,1)
        {
            fpk(1,n,1)
            {
                x[i].S+=q[i][j][k];
                y[j].S+=q[i][j][k];
                z[k].S+=q[i][j][k];
            }
        }
    }
    sort(x+1,x+n+1,cc);
    sort(y+1,y+n+1,cc);
    sort(z+1,z+n+1,cc);
    int fx[n+1],fy[n+1],fz[n+1];
    fpi(1,n,1)
    {
        fx[x[i].F] = i;
        fy[y[i].F] = i;
        fz[z[i].F] = i;
    }
    fpi(1,n,1) cout<<fx[i]<<" "; cout<<endl;
    fpi(1,n,1) cout<<fy[i]<<" "; cout<<endl;
    fpi(1,n,1) cout<<fz[i]<<" "; cout<<endl;
}
int main()
{
    IOS;
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    int t=1;
    //cin>>t;
    while(t--) solve();
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}