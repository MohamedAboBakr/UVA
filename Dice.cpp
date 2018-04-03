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
   int t;scanf("%d",&t);
   while(t--){
      string ar1,ar2;
      cin>> ar1 >> ar2;
      char arr1[6],arr2[6];
      arr1[0]=ar1[0];arr1[1]=ar1[2];arr1[2]=ar1[3];arr1[3]=ar1[5];arr1[4]=ar1[4];arr1[5]=ar1[1];
      arr2[0]=ar2[0];arr2[1]=ar2[2];arr2[2]=ar2[3];arr2[3]=ar2[5];arr2[4]=ar2[4];arr2[5]=ar2[1];
       int ff=0;
       for(int i=0;i<perms.size();i++){
           int f=1;
           for(int j=0;j<6;j++){
              if(arr1[perms[i][j]-1] != arr2[j]) {
                  f=0; break;
              }
           }
           if(f==1){
             printf("Equal\n");
             ff=1;
             break;
           }
       }
       if(!ff) printf("Not Equal\n");
   }

   return 0;
}
