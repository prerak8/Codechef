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
#define d(x) cout<<x<<endl;
ll q[1000000];
int mod(int a)
{
    if(a>=0)return a;
    else return -1*a;
}
int main()
{
    ll t,n,i,j;
    ll a,b;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;a=b=0;
        for(j=0;j<n;j++)
        {
            cin>>q[j];
            if(q[j]<0){a++;}else{b++;}
        }
        if(a==0){cout<<b<<" "<<b<<endl;}
        else if(b==0){cout<<a<<" "<<a<<endl;}
        else {cout<<max(a,b)<<" "<<min(a,b)<<endl;}
    }
}