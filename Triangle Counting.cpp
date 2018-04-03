#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair < int,int > pi;

int adj_mat[3000][3000];
map<int, vector< int > > adj_list;


int main(){
   int t,n,m,u,v; scanf("%d",&t);
   while(t--){
        memset(adj_mat,0,sizeof(adj_mat));
        adj_list.clear();
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
             scanf("%d%d",&u,&v);u--;v--;
             adj_mat[u][v]=adj_mat[v][u]=1;
             adj_list[u].push_back(v);
             adj_list[v].push_back(u);
        }
        ll ans=0;
        map<int, vector< int > >::iterator it=adj_list.begin();
        for(;it!=adj_list.end();it++){
              for(int i=0;i<it->second.size();i++){
                  int tri=0;
                  for(int j=i+1;j<it->second.size();j++){
                       if(adj_mat[it->second[i]][it->second[j]]==1) tri++;
                       if(tri==2) break;
                  }
                ans += tri;
              }
        }
        printf("%lld\n",ans/3);
   }
   return 0;
}
