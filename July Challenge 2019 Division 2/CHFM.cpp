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
#define maxn 100009
double q[maxn];
int main()
{
    IOS;    
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    int n,t,temp;double mean,n1,an,tot,cc;
    cin>>t;
    fpi(1,t,1)
    {
        cin>>n;
        n1 = n;
        tot = 0;cc = 1;
        fpj(1,n,1)
        {
            cin>>q[j];
            tot+=q[j];
        }
        mean=tot/n;
        an = mean*(n-1);
        an = tot - an;
        fpj(1,n,1) if(q[j]==an) {d(j) cc = 0 ;break;}
        if(cc) d("Impossible")
    }
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}