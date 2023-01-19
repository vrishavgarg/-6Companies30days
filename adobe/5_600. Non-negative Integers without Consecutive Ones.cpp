#include<bits/stdc++.h>
using namespace std;

int findIntegers(int n) {
    vector<int> v(32);
    v[0]=1;
    v[1]=2;
    for(int i=2; i<32; i++){
        v[i]=v[i-1]+v[i-2];
    }
    int s=1,p=0;
    for(int i=31; i>=0; i--){
        if(((1<<i)&n) != 0){
            s+=v[i];
            if(p==1){
                s--;
                break;
            }
            p=1;
        }else p=0;
    }
    return s;
}

int main(){

    int n=5;
    cout<<findIntegers(n);

    return 0;
}