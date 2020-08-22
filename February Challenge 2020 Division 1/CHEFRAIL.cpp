#include <bits/stdc++.h>
//#define int long long
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
const int inf = 100000000000;
#define maxn 200005
#define mod 1000000007
vector<int> v1,temp;int mm = 0;
unordered_map<int,int> facmap;
vector<int> v[100001];
void factor(int a)
{
    v1.clear();temp.clear();
    fpi(1,sqrt(a),1)
    {
        if(a%i==0)
        {
            if(a/i==i)
            {
                v1.pb(i);
            }
            else
            {
                v1.pb(i);
                temp.pb(a/i);
            }
        }
    }
    facmap.clear();
    while(!temp.empty()) {v1.pb(temp.back()); temp.pop_back();}
    int l = v1.size();
    fpi(0,l-1,1)
    {
        fpj(i,l-1,1)
        {
            if(v1[i]*v1[j]>100000) break;
            if(facmap.find(v1[i]*v1[j])==facmap.end()) {v[a].pb(v1[i]*v1[j]);facmap[v1[i]*v1[j]]=1;}
        }
    }
}
void build()
{
    fpi(1,100000,1) factor(i);
}
void solve()
{
    int n,m,l,tfac;
    cin>>n>>m;
    int x[n+1],y[m+1];
    unordered_map<int,int> mx,my;
    fpi(1,n,1) {cin>>x[i];mx[x[i]]++;}
    fpi(1,m,1) {cin>>y[i];my[y[i]]++;}
    long long int ans = 0;
    fpi(1,n,1)
    {
        if(x[i]==0)
        {
            ans+=((long long int)n-1)*m;
            continue;
        }
        int l = v[abs(x[i])].size();
        fpj(0,l-1,1)
        {
            tfac = v[abs(x[i])][j]; 
            if(((long long int)x[i])*x[i]>(long long int)tfac*100000) continue;
            if(my.find(tfac)!=my.end() && my.find(-(((long long int)x[i])*x[i]/tfac))!=my.end()) ans++;
        }
    }
    fpi(1,m,1)
    {
        if(y[i]==0)
        {
            ans+=((long long int)m-1)*n;
            continue;
        }
        int l = v[abs(y[i])].size();
        fpj(0,l-1,1)
        {
            tfac = v[abs(y[i])][j]; 
            if(((long long int)y[i])*y[i]>(long long int)tfac*100000) continue;
            if(mx.find(tfac)!=mx.end() && mx.find(-(((long long int)y[i])*y[i]/tfac))!=mx.end()) ans++;
        }
    }
    d(ans)
}   
int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    build();
    int t=1;
    cin>>t;
    while(t--) solve();
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}