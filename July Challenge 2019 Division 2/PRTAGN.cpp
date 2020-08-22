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
int count(int a)
{
    int ans = 0;
    while(a)
    {
        ans++;
        a&=(a-1);
    }
    return ans;
}
int main()
{
    IOS;    
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    int t,q,n,odd,even,temp,to,te;set<int> s;
    cin>>t;
    while(t--)
    {
        s.clear();
        cin>>q;
        fpi(1,q,1)
        {
            cin>>n;
            if(s.find(n)==s.end())
            {
                odd = 0;
                even = 0;
                for(auto it = s.begin();it!=s.end();it++)
                {
                    s.insert(((*it)^n));
                }
                s.insert(n);
                for(auto it = s.begin();it!=s.end();it++)
                {
                    if(count(*it)%2==0) even++; else odd++;
                }
            }
            cout<<even<<" "<<odd<<endl;
        }
    }   
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}