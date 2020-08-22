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
void solve()
{
    int n,l,r,maxleft = -5,minright = INT_MAX;
    map<int,int> mp,st;
    map<int,int>::iterator itr; 
    cin>>n;
    fpi(1,n,1)
    {
        cin>>l>>r;
        mp[l]++;
        mp[r]--;
        maxleft = max(maxleft,l);
        minright = min(minright,r);
    } 
    for(auto i = mp.begin();i!= mp.end();i++)
    {
        if(i!=mp.begin())
        {
            i->second+=itr->second;
        }
        itr = i;
    }
    int count = 0,mi = INT_MAX;
    for(auto i = mp.begin();i!= mp.end();i++)
    {
        if(i->second==0) count++;
        if(maxleft>(i->first) && (i->first)>=minright) mi = min(i->second,mi);
    }
    if(count>1) d(0)
    else
    {
        if(mi==INT_MAX) d(-1)
        else d(mi)
    }
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
