#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int n,m;
int arr[10][10];
int visit[11];
int f=0;

void dfs(int index, int path, vector<int> vec){

    if(path == m){
    	f=1;
    	printf("(%d",vec[0]);
    	for(int i=1;i<vec.size();i++){
          printf(",%d",vec[i]);
    	}
    	printf(")\n");
    	return;
    }

    for(int i=0;i<n;i++){
      if(visit[i]==0 && arr[index][i]==1){
      	 vec.push_back(i+1);
      	 visit[i]=1;
      	 dfs(i,path+1,vec);
      	 vec.erase(vec.begin()+vec.size()-1);
      	 visit[i]=0;
      }
    }

}


void solve(){
	  if(m>n){
	  	printf("no walk of length %d\n",m);
	  	return ;
	  }
    visit[0]=1;
	  for(int i=0;i<n;i++){
        if(arr[0][i]==1){
        	vector<int> vec; vec.push_back(1); vec.push_back(i+1);
        	visit[i]=1;
        	dfs(i,1,vec);
        	visit[i]=0;
        }
	  }

	  if(f==0){
	  	printf("no walk of length %d\n",m);
	  }
}
int main(){
	int x,y=0;
	while(scanf("%d %d",&n,&m) == 2){
		if(y) puts("");
		y=1;
    memset(visit,0,sizeof(visit));
    f=0;
    for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             scanf("%d",&arr[i][j]);
         }
    }
    solve();
    scanf("%d",&x);
	}
	return 0;
}