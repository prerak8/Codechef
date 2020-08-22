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
void solve()
{
    int n;
    cin>>n;
    int a[n],b[n],t1,t2;
    fpi(1,n-1,1) cin>>t1>>t2>>b[i];
    fpi(0,n-1,1) cin>>a[i];
    sort(b+1,b+n,greater<int> ());
    sort(a,a+n,greater<int> ());
    queue<int> q;
    fni(n-1,0,1) q.push(a[i]);
    int ans = 0;n--;
    while(!q.empty())
    {
        if(q.size()==1)
        {
            if(q.front()<b[1]) ans++;
            q.pop();
        }
        else
        {
            if(q.front()<b[n])
            {
                q.pop();
                q.push(INT_MAX);
                ans++;
            }
            else
            {
                q.pop();
                n--;
            }
        }
    }
    d(ans)
}
int main()
{
    IOS;
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    int t;
    cin>>t;
    while(t--) solve();
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}