#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int graph[30][30];
int mx=0;
int n,m;
int dfs(int v, int path){
   if(path>mx) mx = path;
   for(int i=0;i<n;i++){
      if(graph[v][i]){
      	graph[v][i]=0;
      	graph[i][v]=0;
      	dfs(i,path+1);
      	graph[v][i]=1;
      	graph[i][v]=1;
      }
   }
}

int main(){
	int v,u;
	scanf("%d%d",&n,&m);
	while(n!=0){
		for(int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        graph[v][u]=1;
        graph[u][v]=1;
		}

	  for(int i=0;i<n;i++){
      	dfs(i,0);
    }
    memset(graph, 0 , sizeof(graph));
	  printf("%d\n",mx);
	  mx=0;
	  scanf("%d%d",&n,&m);    
	}

	return 0;
}