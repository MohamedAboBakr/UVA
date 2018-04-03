#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;


int main(){
  int n; scanf("%d",&n);
  while(n){
    int flag=0;
    for(int n1=1234;n1<=98765/n ;n1++){
        int n2 = n1*n;
        int bit=(n1<10000),tmp;
        tmp=n1;
        while(tmp){
            bit |= 1<<(tmp%10); tmp/=10;
        }
        tmp=n2;
        while(tmp){
            bit |= 1<<(tmp%10); tmp/=10;
        }
        if(bit==(1<<10)-1){
             flag=1;
             printf("%0.5d / %0.5d = %d\n",n2,n1,n);
        }
    }
    if(!flag) printf("There are no solutions for %d.\n",n);
    scanf("%d",&n);
    if(n!=0) printf("\n");
  }
  return 0;
}
