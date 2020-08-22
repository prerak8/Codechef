#include <bits/stdc++.h>
#define int long long
using namespace std;
void pv(vector<int> v){cout<<v.size()<<endl;  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
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
const int inf = 2000000;
#define maxn 500005
#define mod 1000000007
int month[13],dp[1600][12],ans1600 = 0;
int is_leapyear(int a)
{
    if(a%400==0) return 1;
    if(a%100==0) return 0;
    if(a%4==0) return 1;
    return 0;
}
int odd_days(int y,int m)
{
    int ans = 0;
    y--;
    ans = 365*y;
    ans+=y/4;
    ans-=y/100;
    ans+=y/400;
    ans%=7;
    y++;
    fpi(1,m-1,1)
    {
        if(i==2 && is_leapyear(y)) ans+=29;
        else ans+=month[i];
    }
    ans++;
    ans%=7;
    return ans;
}
void build()
{
    fpi(1,1599,1)
    {
        fpj(1,12,1)
        {
            if(j==1) dp[i][j] = dp[i-1][12];
            else dp[i][j] = dp[i][j-1];
            if(j==2)
            {
                if(odd_days(i,j)==6) dp[i][j]++;
                else if(odd_days(i,j)==0 && is_leapyear(i)==0) dp[i][j]++;
            }
        }
    }
    ans1600 = dp[1599][12];
}
int cal(int y,int m)
{
    int ans = (y/1600)*ans1600;
    y%=1600;
    ans+=dp[y][m];
    return ans;
}
void solve()
{
    int m1,y1,m2,y2;
    cin>>m1>>y1;
    cin>>m2>>y2;
    if(y1==1)
    {
        y1--;
        m1=12;
    }
    else m1--;
    d(cal(y2,m2)-cal(y1,m1))
} 
int32_t main(){
    IOS;
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    month[1] = 31;
    month[2] = 28;
    month[3] = 31;
    month[4] = 30;
    month[5] = 31;
    month[6] = 30;
    month[7] = 31;
    month[8] = 31;
    month[9] = 30;
    month[10] = 31;
    month[11] = 30;
    month[12] = 31;
    build();
    int n=1;
    cin>>n;
    while(n--){
        solve();
    }
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}