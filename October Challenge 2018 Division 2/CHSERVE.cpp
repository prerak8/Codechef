#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
   int n,i,j,k;
   cin>>n;
   int q[n][3];
   for(i=0;i<n;i++)
   {
       cin>>q[i][0]>>q[i][1]>>q[i][2];
   }
   for(i=0;i<n;i++)
   {
       k=q[i][2];
       j=q[i][0]+q[i][1];
       if((j/k)%2==0){cout<<"CHEF";}else{cout<<"COOK";}
       cout<<endl;
   }
}
