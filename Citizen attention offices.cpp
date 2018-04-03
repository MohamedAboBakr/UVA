#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair < int,int > pi;
vector< vector < int > > perms;
ll arr[5][5];

void _generate(){
    for(int i=0;i<=20;i++){
        for(int j=i+1;j<=21;j++){
            for(int k=j+1;k<=22;k++){
                for(int u=k+1;u<=23;u++){
                    for(int v=u+1;v<=24;v++){
                         vector <int> vec;
                         vec.push_back(i);vec.push_back(j);vec.push_back(k);vec.push_back(u);vec.push_back(v);
                         perms.push_back(vec);
                    }
                }
            }
        }
    }
}


void getXY(int cell ,int *x ,int *y){
    *x = cell/5;
    *y = cell%5;
}

ll dist(vector<int> vec){
     vector <pi> vec2 ;
     for(int i=0;i<5;i++){
         int x,y;
         getXY(vec[i],&x,&y);
         vec2.push_back(pi(x,y));
     }
     ll mnn = 0L;
     for(int i=0;i<5;i++){
          for(int j=0;j<5;j++){
              ll mn = 10;
              for(int k=0;k<5;k++){
                  mn = min(mn ,(ll)abs(i-vec2[k].first)+(ll)abs(j-vec2[k].second));
              }
              mnn += mn*arr[i][j];
          }
     }
     return mnn;
}

int main(){
   _generate();
   int t,n,x,y; scanf("%d",&t);
   ll val;
   while(t--){
      memset(arr,0,sizeof(arr));
      scanf("%d",&n);
      while(n--){
         scanf("%d%d%lld",&x,&y,&val);
         arr[x][y]=val;
      }

    ll mn = dist(perms[0]);
    vector<int> anss = perms[0];
    for(int i=1;i<perms.size();i++){
         ll ans = dist(perms[i]);
         if(ans<mn){
             mn = ans;
             anss = perms[i];
         }
    }
    printf("%d %d %d %d %d\n",anss[0],anss[1],anss[2],anss[3],anss[4]);
   }
   return 0;
}
