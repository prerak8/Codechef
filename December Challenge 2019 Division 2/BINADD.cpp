#include <bits/stdc++.h>
#define ll long long
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
#define maxn 750000
//#define mod (long long int)10e9+7
string zeros(int a)
{
    string ans = "";
    fpi(1,a,1) ans+="0";
    return ans;
}
void solve()
{
    int tot = 0,odd = 0,val=0;
    string a,b;
    cin>>a;
    cin>>b;
    int al = a.size(),bl = b.size(),ml,temp = -1;
    ml = max(al,bl);
    a = zeros(ml-al) + a;
    b = zeros(ml-bl) + b;
    std::vector<int> v;
    v.pb(0);
    fni(ml-1,0,1)
    {
        if(a[i]=='1' && b[i]=='1')
        {
            if(temp!=-1) val = max(val,temp-i+1);
            temp = i;
        }
        else if(a[i]=='0' && b[i]=='1')
        {
            val = max(val,1);
        }
        else if(a[i]=='0' && b[i]=='0')
        {
            if(temp!=-1) val = max(val,temp-i+1);
            temp = -1;
        }
    }
    if(temp!=-1) val = max(val,temp+2);
    d(val)
}
int main(){
    IOS;
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    int n;
    cin>>n;
    while(n--){
        solve();
    }
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}
