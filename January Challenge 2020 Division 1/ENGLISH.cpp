#include <bits/stdc++.h>
#define int long long
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
#define maxn 1000005
#define mod (int)10e9+7
int fans = 0;
struct trie
{
    trie* dp[26];
    int end;
};
trie* getnod()
{
    trie* ans = new trie;
    fpi(0,25,1) ans->dp[i] = NULL;
    ans->end = 0;
    return ans;
}
void insert(trie* root,string s)
{
    int l = s.size();
    fpi(0,l-1,1)
    {
        if(root->dp[s[i]-'a']==NULL) root->dp[s[i]-'a'] = getnod();
        root = root->dp[s[i]-'a'];
    }
    root->end++;
}
int dfs(trie* root,int h)
{
    int ans = 0;
    fpi(0,25,1)
    {
        if(root->dp[i]) ans+=dfs(root->dp[i],h+1);
    }
    ans+=root->end;
    if(h%2==0)
    {
        fans+=(ans/2)*(h)*h;
        ans%=2;
    }
    return ans;
}
void solve()
{
    fans= 0;
    int n,l;
    string s,temp;
    cin>>n;
    trie* root = getnod();
    fpi(1,n,1)
    {
        cin>>s;
        l = s.size();
        temp = s + s;
        fpi(0,l-1,1) temp[2*i] = s[i];
        rev(s);
        fpi(0,l-1,1) temp[2*i+1] = s[i];
        insert(root,temp);
    }
    dfs(root,0);
    d(fans/4)
}
int32_t main()
{
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    int t;
    cin>>t;
    while(t--) solve();
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}