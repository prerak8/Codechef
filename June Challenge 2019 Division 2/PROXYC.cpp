#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
void pv(std::vector<int> v){cout<<v.size()<<endl;  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
void pa(int a[],int n,int p){for (int i = p; i < n+p; ++i){cout<<a[i]<<" ";}cout<<""<<endl;}
#define mem(a,b) memset(a,b,sizeof(a))
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
#define mod 777997998244353
const int inf = (int)10e9 + 8;
#define maxn 100009
int main()
{
    IOS;
    int t,tot,an, P,pro,n;
    string s;
    cin>>t;
    fpk(1,t,1)
    {
        cin>>n;
        cin>>s;
        pro=0;P = 0;an = 1; 
        fpi(0,n-1,1) if(s[i]=='P') P++;
        if((P*100)/n >= 75){d(pro) an=0; continue;}
        fpi(2,n-3,1)
        {
            if(s[i]=='A' && (s[i-1]=='P' || s[i-2]=='P') && (s[i+1]=='P' || s[i+2]=='P'))
            {
                P++;pro++;
                if((P*100)/n >= 75){d(pro) an=0; break;}
            }
        }
        if(an) d(-1)
    }
}