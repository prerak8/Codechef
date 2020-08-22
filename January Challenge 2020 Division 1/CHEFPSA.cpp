#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_map>
typedef long long ll;
using namespace std;
int mod = 1000000007;
ll power1(int x,int y) 
{
    if (y == 0) 
        return 1LL; 
    ll p = power1(x, y / 2);
    p = (p * p) % mod; 
    return (y % 2 == 0) ? p : (x * p) % mod; 
} 
ll invmod(int a)
{
    return power1(a,1000000005);
}
int32_t main()
{
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    ll pow2[100005],fact[100005];int temp;
    pow2[0] = 1;
    fact[0] = 1;
    int pp=100004;
    while(pp--)
    {
        int i=100004-pp;
        pow2[i] = (pow2[i-1]*2);
        pow2[i]%=mod;
        fact[i] = (fact[i-1]*i);
        fact[i]%=mod;
    }
    while(q--)
    {
        int n;
        cin>>n;
        ll tot = 0;
        vector<int> v;
        unordered_map<int,int> mp,fa;
        for(int i=0;i<2*n;i++)
        {
            cin>>temp;
            v.push_back(temp);
            tot+=temp;
            mp[temp]++;
        }
        if(tot%(n+1))
        {
            cout<<0<<'\n';
            continue;
        }
        int tt = tot/(n+1);
        v.push_back(0);
        v.push_back(0);
        sort(v.begin(),v.end());
        mp[0]+=2;
        int vl = v.size(),flag = 0;
        int dd=vl;
        while(dd--)
        {
            int i=vl-1 - dd;
            if(mp[v[i]]==0) continue;
            mp[v[i]]--;
            if(mp[tt-v[i]]==0)
            {
                flag = 1;
                break;
            }
            mp[tt-v[i]]--;
            fa[v[i]]++;
        }
        if(fa[min(0,tt)]<2 || flag)
        {
            cout<<0<<'\n';
            continue;
        }
        fa[min(0,tt)]-=2;
        ll ans = fact[n-1];
        for(auto i = fa.begin();i!=fa.end();i++)
        {
            if(i->first== tt - i->first  )
            {
                ans*=invmod(fact[i->second]);
                ans%=mod;
            }
            else
            {
                ans*=pow2[i->second];
                ans%=mod;
                ans*=invmod(fact[i->second]);
                ans%=mod;
            }
        }
        cout<<ans<<'\n';
    }
}