#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef vector< int >vi;
typedef pair< vi,vi > pvi;
vector<pvi> perms;

struct player{
   string name;
   int x,y;
};
player p[10];

void _generate(){
     for(int i=0;i<10;i++){
         for(int j=i+1;j<10;j++){
             for(int k=j+1;k<10;k++){
                 for(int q=k+1;q<10;q++){
                    for(int w=q+1;w<10;w++){
                         vi v1,v2;
                         v1.push_back(i);v1.push_back(j);v1.push_back(k);v1.push_back(q);v1.push_back(w);
                         for(int r=0;r<10;r++){
                            if(r!=i&&r!=j&&r!=k&&r!=q&&r!=w) v2.push_back(r);
                         }
                         perms.push_back(pvi(v1,v2));
                    }
                 }
             }
         }
     }
}

bool comp(vector<string> v1, vector<string> v2){
     sort(v1.begin(),v1.end());
     sort(v2.begin(),v2.end());
     for(int i=0;i<5;i++){
         if(v1[i]<v2[i]) return true;
     }
     return false;
}


int main(){
 _generate();
 int t; scanf("%d",&t);
 for(int j=1;j<=t;j++){
     for(int i=0;i<10;i++){
       string s; int x,y;
       cin>>s>>x>>y;
      p[i].name=s;p[i].x=x;p[i].y=y;
     }
    vector<string>v1,v2;
    int mx1=0,mx2=0;
    for(int i=0;i<perms.size();i++){
         int s1=-1,s2=-1;
         vector<string> vv1,vv2;
         for(int k=0;k<5;k++){
            s1+=p[perms[i].first[k]].x;
            s2+=p[perms[i].second[k]].y;
            vv1.push_back(p[perms[i].first[k]].name);
            vv2.push_back(p[perms[i].second[k]].name);
         }
         if(s1>mx1 || (s1==mx1 && s2>mx2)){
             v1=vv1;v2=vv2; mx1=s1; mx2=s2;
         }
         else if(s1==mx1&&s2==mx2){
              if(comp(vv1,v1)){
                v1=vv1;v2=vv2;
              }
         }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
     printf("Case %d:\n",j);
      cout<< "("<<v1[0];
      for(int i=1;i<5;i++){
         cout <<", "<<v1[i];
      }cout <<")\n";
      cout<<"("<<v2[0];
      for(int i=1;i<5;i++){
        cout <<", "<<v2[i];
      }cout <<")\n";
 }
 return 0;
}

/*

struct player{
   string name;
   int x,y;
   bool operator<(const player& p)const {
      if(x!=p.x) return x>p.x;
      if(y!=p.y) return y<p.y;
      return name<p.name;
  }
};

int main(){
  int t,n; scanf("%d",&t);
  for(int j=1;j<=t;j++){
      vector<player> pls;
      string name;int x,y;
      for(int i=0;i<10;i++){
         cin >> name >> x >> y;
         player p ;
         p.x=x;p.y=y;p.name=name;
         pls.push_back(p);
      }
      sort(pls.begin(),pls.end());
      vector<string>v1,v2;
      for(int i=0;i<5;i++){
          v1.push_back(pls[i].name);
      }
      for(int i=5;i<10;i++){
          v2.push_back(pls[i].name);
      }
      sort(v1.begin(),v1.end());sort(v2.begin(),v2.end());
      printf("Case %d:\n",j);
      cout<< "("<<v1[0];
      for(int i=1;i<5;i++){
         cout <<", "<<v1[i];
      }cout <<")\n";
      cout<<"("<<v2[0];
      for(int i=1;i<5;i++){
        cout <<", "<<v2[i];
      }cout <<")\n";
  }
  return 0;
}


*/
