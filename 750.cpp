#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int a[8], b[8], c[8],d[8];
int x,y;

vector< vector<int> > ans;
int check(int r, int i){
       for(int j=0;j<r;j++){
            if(abs(b[j]-r) == abs(c[j]-i)) return 0;
       }
       return 1;
}


void solve(int row, int fixed){
   if(row == 8){
      if(d[y]==x){
        vector<int> v;
        for(int i=0;i<8;i++){
             v.push_back(d[i]+1);
        }
        ans.push_back(v);
      }
        return;
   }
   
   else{
   for(int i=0;i<8;i++){
       if(a[i]==0 && check(row, i)){
       	    a[i]=1; b[row] = row; c[row] = i; d[i]=row;
            solve(row+1,fixed);
            a[i]=0;
       }
   }
 }
}

int main(){
  int t; scanf("%d",&t);
  for(int i=1;i<=t;i++){
      for(int j=0;j<8;j++) a[j]=0;
      scanf("%d%d",&x,&y);x--;y--;
      solve(0,x);
      sort(ans.begin(), ans.end());
      printf("SOLN       COLUMN\n");
      printf(" #      1 2 3 4 5 6 7 8\n\n");
      for(int j=0;j<ans.size();j++){
        printf("%2d      ",j+1);
        for(int k=0;k<8;k++){
          printf("%d",ans[j][k]);
          if(k==7) printf("\n");
          else printf(" ");
        }
      }
      if(i!=t)printf("\n");
      ans.clear();
  }
	return 0;
}