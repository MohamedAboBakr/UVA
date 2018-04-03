#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

ll s2[101],s3[101],s4[101];
ll R2[101],R3[101],R4[101];

void solve_S(){
   for(ll i=1;i<=100;i++){
      s2[(int)i] = s2[(int)i-1]+i*i;
      s3[(int)i] = s3[(int)i-1]+i*i*i;
      s4[(int)i] = s4[(int)i-1]+i*i*i*i;
   }
}

void solve_R(){
     for(ll i=1;i<=100;i++){
          for(ll j=1;j<=i;j++){
               for(ll k=1;k<=i;k++){
                   if(k>j)R2[(int)i]+=(i-j+1)*(i-k+1)*2;
                   R3[(int)i]+=(i-j+1)*(i-k+1)*(i+1)*i/2;
                   R4[(int)i]+=(i-j+1)*(i-k+1)*i*(i+1)/2*i*(i+1)/2;
               }
          }
     }
}

int main(){
 solve_S();
 solve_R();
 int n;
 while(scanf("%d",&n)==1){
     printf("%lld %lld %lld %lld %lld %lld\n",s2[n],R2[n],s3[n],R3[n]-s3[n],s4[n],R4[n]-s4[n]);
 }
  return 0;
}
