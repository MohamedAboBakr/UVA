#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main(){
  int arr[1001];
  for(int i=1;i<=1000;i++){
       int mn = 10000000;
       for(int j=1;j<=(int)sqrt(i);j++){
          if(i%j==0){
                for(int k=1;k<=(int)sqrt(i/j);k++){
                     if((i/j)%k==0){
                         int d1,d2,d3,mm;
                         d1=j;d2=k;d3=i/(j*k);
                         mm = d1*d2*2+d1*d3*2+d2*d3*2;
                         mn = min(mn,mm);
                     }
                }

          }
          arr[i]=mn;
       }
  }
  int t,n; scanf("%d",&t);
  while(t--){
     scanf("%d",&n);
     printf("%d\n",arr[n]);
  }
  return 0;
}
