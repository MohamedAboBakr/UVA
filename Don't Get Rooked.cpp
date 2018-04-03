#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

vector<string> grid;
map<int,int> upperBnd;
vector<vector<int> > perms;

void getXY(int n,int num,int *x,int *y){
    *x = num/n;
    *y = num%n;
}

bool capture(int x1,int y1,int x2,int y2){
  if(grid[x1][y1]=='X'||grid[x2][y2]=='X') return true;
  if(x1!=x2 && y1!=y2) return false;
  if(x1==x2){
      for(int i=min(y1,y2)+1;i<=max(y1,y2)-1;i++){
         if(grid[x1][i]=='X') return false;
      }
      return true;
  }
    for(int i=min(x1,x2)+1;i<=max(x1,x2)-1;i++){
         if(grid[i][y1]=='X') return false;
    }
    return true;
}

bool validate(vector<int> perm , int n){

     for(int i=0;i<perm.size();i++){
           int x1,y1; getXY(n,perm[i],&x1,&y1);
           if(perm.size()==1&&grid[x1][y1]=='X') return false;
           for(int j=i+1;j<perm.size();j++){
               int x2,y2; getXY(n,perm[j],&x2,&y2);
               if(capture(x1,y1,x2,y2)) return false;
           }
     }
     return true;
}

void _generate(int n,int index,int tk,int curr,vector<int> perm){
     if(curr==tk){
         if(validate(perm,n)){
             vector<int> v=perm;
             perms.push_back(v);
         }
         return;
     }

     for(int i=index;i<=n*n-tk+curr;i++){
        perm.push_back(i);
        _generate(n,i+1,tk,curr+1,perm);
        perm.erase(perm.begin()+perm.size()-1);
     }
}

int mxx(int n){
    for(int i=upperBnd[n];i>0;i--){
        perms.clear();
        vector<int>v;
        _generate(n,0,i,0,v);
        if(perms.size()!=0) return i;
    }
    return 0;
}

int main(){
  upperBnd[4]=8;upperBnd[3]=5;upperBnd[2]=2;upperBnd[1]=1;
  int n; scanf("%d",&n);
  while(n){
    grid.clear();
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        grid.push_back(s);
    }
    int ans=mxx(n);
    printf("%d\n",ans);
    scanf("%d",&n);
  }
  return 0;
}
