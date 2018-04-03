#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int a[8], b[8], c[8], d[8];

int check(int col, int i){
       for(int j=0;j<col;j++){
            if(abs(c[j]-i) == abs(d[j]-col)) return 0;
       }
       return 1;
}

int mn = 9;
void solve(int col, int chg){
   if(col == 8){
        if(chg<mn) mn = chg;
        return;
   }

   for(int i=0;i<8;i++){
       if(b[i]==0 && check(col, i)){
       	    b[i]=1; c[col] = i; d[col] = col;
            int f = (a[col]==i)?0:1;
            solve(col+1,f+chg);
            b[i]=0;
       }
   }
}

int main(){
	int tst=1;
	while(scanf("%d",&a[0]) == 1){
		 b[0] = 0;
		 a[0]--;
     for(int i=1;i<8;i++){
         scanf("%d",&a[i]);
         b[i] = 0;
         a[i]--;
     }
     mn = 9;
     solve(0,0);
    printf("Case %d: %d\n",tst,mn);
    tst++;
	}
	return 0;
}