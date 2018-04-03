#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int> pi;
typedef pair<ll,pi> ppi;
ll grid[1025][1025];

int main(){
  int t,d,n,x,y,sz; scanf("%d",&t);
  while(t--){

      memset(grid,0,sizeof(grid));
      ll ans=0;int xx,yy;
      scanf("%d%d",&d,&n);
      for(int i=0;i<n;i++){
        scanf("%d%d%d",&x,&y,&sz);
        int mnx=max(0,x-d),mxx=min(1024,x+d);
        int mny=max(0,y-d),mxy=min(1024,y+d);
        for(int j=mnx;j<=mxx;j++){
            for(int k=mny;k<=mxy;k++){
                grid[j][k]+=sz;
                if(grid[j][k]>ans){
                    ans=grid[j][k];xx=j;yy=k;
                }else if(grid[j][k]==ans&&j<xx){
                    xx=j;yy=k;
                }else if(grid[j][k]==ans&&j==xx&&k<yy){
                    yy=k;
                }
            }
        }
      }
      printf("%d %d %lld\n",xx,yy,ans);
  }
  return 0;
}
