#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>
#include <string.h>
#include <queue>
#include <map>
#define ll long long int 
using namespace std;
const double pi=3.141592653589793238;
const ll inf = (ll)10e16;
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define d(x) cout<<x<<endl;
#define fni(x,y,z) for(int i=x;i>=y;i-=z)
#define fnj(x,y,z) for(int j=x;j>=y;j-=z)
#define fpi(x,y,z) for(int i=x;i<=y;i+=z)   
#define fpj(x,y,z) for(int j=x;j<=y;j+=z)
#define fpk(x,y,z) for(int k=x;k<=y;k+=z)   
#define fnk(x,y,z) for(int k=x;k>=y;j-=z)
#define pb push_back
#define mod 1000000007
int main()
{
    IOS;
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    int t,mx=0,temp,k1,ans;
    int n,q[20001];
    multiset <int,greater <int> > cc;
    map <int ,int> map;
    cin>>t;
    fpk(1,t,1)
    {
        ans=0;mx=0;
        cin>>n>>k1;
        fpi(1,n,1) {cin>>q[i];}
        fpi(1,n,1)
        {
            mx=0; cc.clear(); map.clear();
            fpj(i,n,1)
            {
                // if(cc.size()<k1) {cc.insert(q[j]);}
                // else {if(*cc.rbegin()>q[j]){cc.erase(*cc.rbegin());cc.insert(q[j]);}}
                mx=max(mx,q[j]);
                map[q[j]]++;
                temp = map[mx];
                if(map[temp]>0) {ans++;}
            } 
        }
        d(ans)
    }
}
    