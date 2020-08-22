#include <math.h>
#include <bits/stdc++.h>
#include <string.h>
#include <queue>
#include <map>
#define ll long long int 
using namespace std;
void pv(std::vector<int> v){  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
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
#define rev(a) reverse(a.begin(),a.end())
const int inf = 1000000;
#define maxn 409
int q[maxn];
int solve(std::vector<int> v)
{
    int l = v.size(),pen,ans =  INT_MAX,fpen=INT_MAX,cc;
    std::vector<int> v1;
    if(l==1) return 0;
    fpi(0,l-1,1)
    {
        if(i!=l-1)
        {
            
            pen = v[i] + v[i+1];
        }
        else
        {
            pen = v[l-1]+v[0];
        }
        if(pen<=fpen) {cc = i;fpen = pen;}
    }
    int i = cc;
    if(i==l-1)
    {
        fpj(1,l-2,1) v1.pb(v[j]);
        v1.pb(v[l-1]+v[0]);
    }
    else
    {
        fpj(0,l-1,1)
        {
            if(j==i) {v1.pb(v[j]+v[j+1]);j++;}
            else v1.pb(v[j]);
        }
    }
    return fpen + solve(v1);
}
int main()
{
    IOS;    
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    int t,n,temp;
    cin>>t;std::vector<int> v;
    while(t--)
    {
        v.clear();
        cin>>n;
        fpi(1,n,1)
        {
            cin>>temp;
            v.pb(temp);
        }
        d(solve(v))
    }
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}