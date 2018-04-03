#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;


int grid[8][8], a[8], b[8] , c[8];
int check(int r, int i){
       for(int j=0;j<r;j++){
            if(abs(b[j]-r) == abs(c[j]-i)) return 0;
       }
       return 1;
}
int ans=0;
void solve(int row,int sum){
    if(row == 8) {
        if(sum>ans){
            ans = sum;
        }
        return;
    }
    for(int i=0;i<8;i++){
         if(a[i]==0 && check(row,i)==1){
         	 a[i]=1; b[row]=row; c[row]=i;
         	 solve(row+1,sum+grid[row][i]);
             a[i]=0;
           }
    }
}

int main(){
	int k;
	scanf("%d",&k);
	for(int i=0; i<k ; i++){
        ans = 0;
		for(int j=0;j<8;j++){
            a[i]=0;
			for(int t=0;t<8;t++){
               scanf("%d",&grid[j][t]);
			}
		}
		solve(0,0);
		printf("%5d\n",ans);
  }
	return 0;
}