#include <bits/stdc++.h>
using namespace std;
#define int long long 
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
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define mod 1000000007
const int inf = 100000000000000000;
#define maxn 300009
int n1,m1;
//https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
void multiply(int F[2][2], int M[2][2]) 
{ 
  int x1 =  (F[0][0]*M[0][0])%mod + (F[0][1]*M[1][0])%mod; 
  int y1 =  (F[0][0]*M[0][1])%mod + (F[0][1]*M[1][1])%mod; 
  int z1 =  (F[1][0]*M[0][0])%mod + (F[1][1]*M[1][0])%mod; 
  int w1 =  (F[1][0]*M[0][1])%mod + (F[1][1]*M[1][1])%mod; 
  
  F[0][0] = x1%mod; 
  F[0][1] = y1%mod; 
  F[1][0] = z1%mod; 
  F[1][1] = w1%mod; 
} 
void power(int F[2][2], int n) 
{ 
  if( n == 0 || n == 1) 
      return; 
  int M[2][2] = {{(m1-1)%mod,(m1-1)%mod},{1,0}}; 
  
  power(F, n/2); 
  multiply(F, F); 
  
  if (n%2 != 0) 
     multiply(F, M); 
} 
void solve()
{
    cin>>n1>>m1;
    int dp[3],ans = 0;
    dp[1] = (m1)%mod;
    dp[2] = (dp[1]*dp[1])%mod;
    if(n1<=2) {d(dp[n1]) return;}
    int mat[2][2] = {{(m1-1)%mod,(m1-1)%mod},{1,0}};
    power(mat,n1-2);
    ans+=(dp[2]*mat[0][0])%mod;
    ans%=mod;
    ans+=(dp[1]*mat[0][1])%mod;
    ans%=mod;
    d(ans)
}
int32_t main()
{
    IOS;
    int t = 1;
    cin>>t;
    while(t--) solve();
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
} 