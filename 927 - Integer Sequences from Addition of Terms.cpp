#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int>pi;
typedef pair<int,pi> ppi;

int main()
{
  int c;scanf("%d",&c);
  while(c--){
      int n;scanf("%d",&n);
      vector<int> vec,poly;
     for(int i=0;i<=n;i++){
          int ai; scanf("%d",&ai);
          vec.push_back(ai);
     }
      int index=0,k,d; scanf("%d%d",&d,&k);
      for(int i=1;i<=20;i++){
            ll tmp=1,sm=0;
            for(int j=0;j<vec.size();j++){
                sm += vec[j]*tmp;
                tmp*=i;
            }
            index += i*d;
            if(index>=k){
                    printf("%lld\n",sm);
                    break;
            }
      }
  }
  return 0;
}
