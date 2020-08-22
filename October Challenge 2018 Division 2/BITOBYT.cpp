#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
   long long int n,i,j,k;
   cin>>n;
   long long int q[n];
   for(i=0;i<n;i++)
   {
       cin>>q[i];
   }
   for(i=0;i<n;i++)
   {
       j=q[i]/26;j=pow(2,j);
       if(q[i]%26<=2&&q[i]%26>0){cout<<j<<" "<<0<<" "<<0;}
       if(q[i]%26>2&&q[i]%26<=10){cout<<0<<" "<<j<<" "<<0;}
       if(q[i]%26>10&&q[i]%26<26){cout<<0<<" "<<0<<" "<<j;}
       if(q[i]%26==0){cout<<0<<" "<<0<<" "<<j/2;}
       cout<<endl;
   }
}
