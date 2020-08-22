#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
void pv(std::vector<int> v){cout<<v.size()<<endl;  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
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
#define mod 777997998244353
const int inf = (int)10e9 + 8;
#define maxn 100009
string add(string A, string B) {
    int temp=0,i,j,la=A.size(),lb = B.size(),l,an;
    string ans,a,b;
    if(lb>la) {a=B,b=A;}
    else {a=A,b=B;}
    la=a.size();lb = b.size();
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(i=0;i<la;i++)
    {
        if(i<lb)
        {
            an = (  (int)a[i] - 48 + (int)b[i] - 48 + temp  )%10;
            temp = (  (int)a[i] - 48 + (int)b[i] - 48 + temp  )/10;
            ans.push_back((char)an+48);
        }
        else
        {
            an = ((int)a[i] - 48 + temp)%10;
            temp = ((int)a[i] - 48 + temp)/10;
            ans.push_back((char)an+48);
        }
    }
    if(temp>0) ans.push_back((char)temp+48);
    reverse(ans.begin(),ans.end());
    return ans;
}
int cc(string s)
{
    int ans = 0,l = s.size();
    fpi(0,l-1,1) ans+=(int)(s[i]-'0');
    return ans;
}
int main()
{
    IOS;
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    string s,ans;int t;
    cin>>t;
    fpi(1,t,1)
    {
        cin>>s;
        ans = s;
        fpi(1,9,1) ans = add(ans,s);
        ans = add(ans,to_string((18000-cc(s))%10));
        d(ans)
    }
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}