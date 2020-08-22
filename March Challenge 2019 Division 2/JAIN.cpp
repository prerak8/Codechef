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
int a[32],d[5];
int db(int *p)
{
    int temp=1,ans=0;
    fpi(0,4,1) ans+=temp*p[i],temp*=2;
    a[ans]++;
}
int main()
{
    IOS;
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    int t,n; string s; ll ans;
    cin>>t;
    fpi(1,t,1) 
    {
        fpk(0,31,1) a[k]=0; cin>>n; ans=0; 
        fpk(1,n,1)
        {

            cin>>s;  fpj(0,4,1) d[j] = 0;
            fpj(0,s.size()-1,1)
            {
                if(s[j]=='a') d[0]=1;
                if(s[j]=='e') d[1]=1;
                if(s[j]=='i') d[2]=1;
                if(s[j]=='o') d[3]=1;
                if(s[j]=='u') d[4]=1;
            }   
            db(d);
        }
        fpk(1,31,1) fpj(k+1,31,1) if((k|j)==31){ans += (a[k]*a[j]);}
        ans+=(a[31]*(a[31]-1))/2;       
        d(ans)  
    }

}