#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;


int main(){
  int k,ss;scanf("%d",&k);
  while(k){
    vector<int> s;
    for(int i=0;i<k;i++){
        scanf("%d",&ss);
        s.push_back(ss);
    }
    int diff=k-6;
    for(int a=0;a<=diff;a++){
        for(int b=a+1;b<=1+diff;b++){
            for(int c=b+1;c<=2+diff;c++){
                for(int d=c+1;d<=3+diff;d++){
                    for(int e=d+1;e<=4+diff;e++){
                        for(int f=e+1;f<=5+diff;f++){
                            printf("%d %d %d %d %d %d\n",s[a],s[b],s[c],s[d],s[e],s[f]);
                        }
                    }
                }
            }
        }
    }
    scanf("%d",&k);
    if(k!=0)printf("\n");
  }
  return 0;
}
