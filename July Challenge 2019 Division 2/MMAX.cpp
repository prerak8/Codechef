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
int q[maxn];
int solve(int n,int temp)
{
    if(temp>=(n/2 + n%2)) temp = n - temp;
    return min(2*temp,n-1);
}
int main()
{
    IOS;    
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    int t,s10,temp,n,l;string k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>k;
        temp = 0;
        l = k.size();
        s10 = 1;
        fni(l-1,0,1)
        {
            temp += (((k[i] - '0')%n)*(s10))%n;
            temp%=n;
            s10 = (s10*10)%n;
        }
        d(solve(n,temp))
    }
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}