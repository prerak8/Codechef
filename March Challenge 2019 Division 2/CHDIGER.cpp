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
#define fni(x,y,z) for(i=x;i>=y;i-=z)
#define fnj(x,y,z) for(j=x;j>=y;j-=z)
#define fpi(x,y,z) for(i=x;i<=y;i+=z)   
#define fpj(x,y,z) for(j=x;j<=y;j+=z)
#define fpk(x,y,z) for(k=x;k<=y;k+=z)   
#define fnk(x,y,z) for(k=x;k>=y;j-=z)
#define pb push_back
#define mod 1000000007
int a[1000001]={0},b[1000001];
int main()
{
    IOS;
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    int t,a=0,i,j,d,z,k,id,cou,l; 
    cin>>t;
    string s;;
    fpk(1,t,1)
    {
       cin>>s;cin>>d;id=0;cou=0;z=0;l=s.size();
       fpj(1,d-1,1)
       {
            cou=0;
            fpi(z,s.size()-1,1)
            {
                if(s[i]-48==j){cou++;id=i;}
            }
            fpi(1,cou,1) {cout<<j;l--;}
            if(cou>0) z=id+1;
       }
       fpj(1,l,1) cout<<d; cout<<endl;
    }

}