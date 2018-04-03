int cnt(int a){  // count the number of 1's bits in binary representation of a number
    int n=0;
    while(a){
        n++;
        a-=(a&-a);  // a&-a get the rightmost 1 bit in a
    }
    return n;
}

vector<int> perms(int n,int m){  // get all permutations to choose m items from n
        vector<int> perm;
        for(int i=1;i<(1<<n);i++){
             if(cnt(i)==m) perm.push_back(i);
        }
        return perm;
}


void print(int n){
    for(int i=0;i<n;i++){
        if(ans&(1<<i))printf(" %d",i+1);
    }
    printf("\n");
}
