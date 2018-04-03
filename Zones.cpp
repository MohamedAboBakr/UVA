#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef vector<int> vi;
typedef pair<vi,int> pvi;
int towers[22];
vector<pvi> intersect;
vector<int> ans;
int maxx=0;


void solve(vector<int>vec,int m){
     int sum=0;
     for(int i=0;i<m;i++){
          sum+=towers[vec[i]];
     }

     for(int i=0;i<intersect.size();i++){
          int cnt=0;
          for(int j=0;j<intersect[i].first.size();j++){
                for(int k=0;k<m;k++){
                     if(vec[k]==intersect[i].first[j]){
                         cnt++;
                         break;
                     }
                }
          }
          if(cnt>1){
             sum -= (cnt-1)*intersect[i].second;
          }
     }

     if(sum>maxx){
        maxx=sum;
        ans=vec;
     }
}
void solve0(int n,int m,int index,int curr,vector<int> vec){
    if(curr==m){
        solve(vec,m);
        return;
    }
    for(int i=index;n-i>=m-(curr+1);i++){
        vec.push_back(i);
        solve0(n,m,i+1,curr+1,vec);
        vec.erase(vec.begin()+vec.size()-1);
    }
}


int main(){

  int n,m,tk,t,val,tw,k=1;
  scanf("%d%d",&n,&tk);
  while(n){
     memset(towers,0,sizeof(towers));
     intersect.clear();
     ans.clear();
     maxx=0;
     for(int i=1;i<=n;i++){
        scanf("%d",&towers[i]);
     }
     scanf("%d",&m);
     for(int i=0;i<m;i++){
        scanf("%d",&t);
        vector<int> sett;
        for(int j=0;j<t;j++){
            scanf("%d",&tw);
            sett.push_back(tw);
        }
        scanf("%d",&val);
        intersect.push_back(pvi(sett,val));
     }
     vector<int>vec;
     solve0(n,tk,1,0,vec);
     printf("Case Number  %d\n",k++);
     printf("Number of Customers: %d\n",maxx);
     printf("Locations recommended:");
     for(int i=0;i<tk;i++){
        printf(" %d",ans[i]);
     }
     printf("\n\n");
     scanf("%d%d",&n,&tk);
  }
  return 0;
}
