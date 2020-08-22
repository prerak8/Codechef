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
int prime = 20016713;
int dd(int a)
{
    return ((a%prime)*(a%prime))%prime;
}
int count(int a,int b,int c,int d)
{
    a = __gcd(a,b);
    fpi(2,31623,1)
    {
        if(a%i==0) return i;
        while(a%i==0 && a)
        {
            a/=i;
        }
    }
    return 0;
}
int main()
{
    IOS;    
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    int t,temp,temp1,l,cc,count;string s;
    cin>>t;
    std::vector<int> v,v1;
    while(t--)
    {
        v.clear();v1.clear();
        cout<<1<<" "<<31623<<endl;
        cin>>temp;
        //temp = dd(31623);
        temp1 = 31623*31623 - temp;
        fpi(2,46320,1)
        {
            count = 0;
            while(temp1%i==0)
            {
                temp1/=i;count++;
            }
            if(i>temp && count) v.pb(i);
        }
        if(temp1>1) v.pb(temp1); 
        cout<<1<<" "<<46320<<endl;
        cin>>temp;
        //temp = dd(46320);
        temp1 = 46320*46320 - temp;
        fpi(2,46320,1)
        {
            count = 0;
            while(temp1%i==0)
            {
                temp1/=i;count++;
            }
            if(i>temp && count) v1.pb(i);
        }
        if(temp1>1) v1.pb(temp1); 
        int l = v.size();
        fpi(0,l-1,1)
        {
            if(binary_search(v1.begin(),v1.end(),v[i]))
            {
                d(2<<" "<<v[i])
                break;
            }
        }
        cin>>s;
    }
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}