#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

vector<int> votes;
int powers[20];
int sum;

void solve(int index,int n,int ind,int tot,int low,int *num){
   if(index==n) return;
   if(tot>=sum) return;
   for(int i=index;i<n;i++){
         if(i==ind)continue;
         if(tot+votes[i]>=low&&tot+votes[i]<sum) *num = *num+1;
         solve(i+1,n,ind,tot+votes[i],low,num);
   }
}

int main(){
  int t,n,vt;
  scanf("%d",&t);
  while(t--){
      votes.clear();
      memset(powers,0,sizeof(powers));
      sum=0;
      scanf("%d",&n);
      for(int i=0;i<n;i++){
        scanf("%d",&vt); sum+=vt;
        votes.push_back(vt);
      }
      sum = sum/2+1;
      for(int i=0;i<n;i++){
          int low=max(sum-votes[i],0);
          int ans=0;
          solve(0,n,i,0,low,&ans);
          powers[i]=ans;
      }
      for(int i=0;i<n;i++){
         printf("party %d has power index %d\n",i+1,powers[i]);
      }
      printf("\n");
  }
  return 0;
}
