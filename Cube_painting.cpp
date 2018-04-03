#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

vector< vector <int> > perms;

vector<vector < int> > solve(vector <int> v){
   vector< vector< int > > ans;
   int i=0;
   while(i<4){
      vector<int> vv; vv.push_back(v[0]);vv.push_back(v[1]);vv.push_back(v[3]);vv.push_back(v[2]);
      ans.push_back(vv);
      i++;
      int tmp = v[3];
      for(int j=3;j>0;j--){
          v[j]=v[j-1];
      }
      v[0]=tmp;
   }
   return ans;
}

void _generate(){
    vector<int>v;
    vector< vector< int > > vec;
    v.push_back(2);v.push_back(3);v.push_back(5);v.push_back(4);
    vec=solve(v);
    for(int i=0;i<vec.size();i++){
         vector<int>perm; perm.push_back(1);
         perm.push_back(vec[i][0]);perm.push_back(vec[i][1]);perm.push_back(vec[i][2]);perm.push_back(vec[i][3]);
         perm.push_back(6);
         perms.push_back(perm);
    }
    v.clear();

    v.push_back(5);v.push_back(3);v.push_back(2);v.push_back(4);
    vec=solve(v);
    for(int i=0;i<vec.size();i++){
         vector<int>perm; perm.push_back(6);
         perm.push_back(vec[i][0]);perm.push_back(vec[i][1]);perm.push_back(vec[i][2]);perm.push_back(vec[i][3]);
         perm.push_back(1);
         perms.push_back(perm);
    }
    v.clear();


    v.push_back(6);v.push_back(3);v.push_back(1);v.push_back(4);
    vec=solve(v);
    for(int i=0;i<vec.size();i++){
         vector<int>perm; perm.push_back(2);
         perm.push_back(vec[i][0]);perm.push_back(vec[i][1]);perm.push_back(vec[i][2]);perm.push_back(vec[i][3]);
         perm.push_back(5);
         perms.push_back(perm);
    }
    v.clear();

    v.push_back(1);v.push_back(3);v.push_back(6);v.push_back(4);
    vec=solve(v);
    for(int i=0;i<vec.size();i++){
         vector<int>perm; perm.push_back(5);
         perm.push_back(vec[i][0]);perm.push_back(vec[i][1]);perm.push_back(vec[i][2]);perm.push_back(vec[i][3]);
         perm.push_back(2);
         perms.push_back(perm);
    }
    v.clear();


    v.push_back(2);v.push_back(6);v.push_back(5);v.push_back(1);
    vec=solve(v);
    for(int i=0;i<vec.size();i++){
         vector<int>perm; perm.push_back(3);
         perm.push_back(vec[i][0]);perm.push_back(vec[i][1]);perm.push_back(vec[i][2]);perm.push_back(vec[i][3]);
         perm.push_back(4);
         perms.push_back(perm);
    }
    v.clear();

    v.push_back(2);v.push_back(1);v.push_back(5);v.push_back(6);
    vec=solve(v);
    for(int i=0;i<vec.size();i++){
         vector<int>perm; perm.push_back(4);
         perm.push_back(vec[i][0]);perm.push_back(vec[i][1]);perm.push_back(vec[i][2]);perm.push_back(vec[i][3]);
         perm.push_back(3);
         perms.push_back(perm);
    }
    v.clear();
}


int main(){
   _generate();
   char ss[13];

   int tt=1;
   while(scanf("%s",ss)==1){
       char arr1[6],arr2[6];
       for(int i=0;i<6;i++){
          arr1[i]=ss[i];
       }
       for(int i=6;i<12;i++){
          arr2[i-6]=ss[i];
       }
       int ff=0;
       for(int i=0;i<perms.size();i++){
           int f=1;
           for(int j=0;j<6;j++){
              if(arr1[perms[i][j]-1] != arr2[j]) {
                  f=0; break;
              }
           }
           if(f==1){
             printf("TRUE\n");
             ff=1;
             break;
           }
       }
       if(!ff) printf("FALSE\n");
       getchar();
   }

   return 0;
}
