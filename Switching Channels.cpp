#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

map<int, vector <vector<int> > > perms;
map<int,vector<int> > aligns;

vector<int> progs;
vector<int> ans;

int mnn;

void _generate(int index ,int n , int arr[8] , vector<int> stk){
       if(index==n){
           vector<int> v;
           for(int i=0;i<n;i++){
              v.push_back(stk[i]);
           }
           perms[n].push_back(v);
           return;
       }
       for(int i=0;i<n;i++){
           if(arr[i]==0){
              arr[i]=1;
              stk.push_back(i);
              _generate(index+1,n,arr,stk);
              arr[i]=0;
              stk.erase(stk.begin()+stk.size()-1);
           }
       }
}


void solve(int n){

    vector<int>tst;
    map<int,vector<int> >::iterator it;
    for(int i=0;i<perms[n].size();i++){
         int mn=0;
         vector<int>v1,v2,v3;
         for(int j=0;j<n;j++){
             v1.push_back(progs[perms[n][i][j]]);
         }
         v2.push_back(v1[0]);
         for(int j=1;j<n;j++){
            v2.push_back(v1[j]+v2[j-1]);
         }
        it=aligns.begin();
        for(;it!=aligns.end();it++){
             int mnnn=0;
             for(int j=0;j<it->second.size();j++){
                   if(it->second[j]<=v2[0]){
                      mnnn+= v2[0]-it->second[j];
                      mn+= v2[0]-it->second[j];
                   }else if(it->second[j]>=v2[n-1]){
                       mnnn+= it->second[j]-v2[n-1];
                       mn+= it->second[j]-v2[n-1];
                   }else {
                      vector<int>::iterator low;
                      low=lower_bound(v2.begin(),v2.end(),it->second[j]);
                      int index=low-v2.begin();
                      int val=min(v2[index]-it->second[j],it->second[j]-v2[index-1]);
                      mnnn+=val;
                      mn+=val;
                   }
             }
             v3.push_back(mnnn);
        }

        if(i==0){
            tst=v3;
            ans=v1;
            mnn=mn;
        }else{
           int f=0;
           for(int j=0;j<v3.size();j++){
              if(v3[j]<tst[j]){
                 f=1;
                 break;
              }else if(v3[j]>tst[j]) break;
           }
           if(f){
             tst=v3;
             ans=v1;
             mnn=mn;
           }
        }
    }
}


int main(){
  for(int i=1;i<=8;i++){
       int arr[8]={0}; vector<int>v;
       _generate(0,i,arr,v);
  }

  int n,m,j=1; scanf("%d",&n);
  while(n){
      progs.clear();
      aligns.clear();
      int pr,imp,tm;
      for(int i=0;i<n;i++){
         scanf("%d",&pr);
         progs.push_back(pr);
      }
      scanf("%d",&m);
      for(int i=0;i<m;i++){
         scanf("%d%d",&imp,&tm);
         aligns[imp].push_back(tm);
      }
      solve(n);
      printf("Data set %d\n",j++);
      printf("  Order:");
      for(int i=0;i<n;i++){
         printf(" %d",ans[i]);
      }
      printf("\n  Error: %d\n",mnn);
      scanf("%d",&n);
 }
  return 0;
}
