#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
void pv(std::vector<int> v){cout<<v.size()<<endl;  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
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
const int inf = (int)10e9 + 8;
#define maxn 100009
ll q[maxn],k1,x;
void pa(ll a[],int n,int p){for (int i = p; i < n+p; ++i){cout<<(a[i]^x)<<" ";}cout<<""<<endl;}
bool cc(int a,int b)
{
    return ((a^x)-a)>((b^x)-b);
}
int main()
{
    IOS;
    ll t,tot,totw,n,tt2;
    cin>>t;
    fpk(1,t,1)
    {
        totw = 0;
        cin>>n;
        fpi(1,n,1) {cin>>q[i];totw+=q[i];}
        cin>>k1>>x;
        sort(q+1,q+n+1,cc);
        // pa(q,n,1);
        // fpi(1,n,1) cout<<q[i]<<" ";
        // cout<<endl;
        tot = 0;
        if(k1==n)
        {
            fpi(1,n,1) tot+=(q[i]^x);
            d(max(tot,totw))
        }
        else
        {
            tt2 = 0;
            fpi(1,n,1) if((q[i]^x)>q[i]) tt2++;
            if(tt2%2==0)
            {
                fpi(1,n,1) if((q[i]^x)>q[i]) tot+=(q[i]^x); else tot+=q[i];
            }
            else
            {
                if(k1%2==1) fpi(1,n,1) if((q[i]^x)>q[i]) tot+=(q[i]^x); else tot+=q[i];
                else
                {
                    for(int i=1;i+1<=n;i+=2)
                    {
                        tot += max(q[i]+q[i+1],(q[i]^x)+(q[i+1]^x));
                    }
                    if(n%2==1) tot+=q[n];
                }
            }
            d(tot)
        }
    }
}