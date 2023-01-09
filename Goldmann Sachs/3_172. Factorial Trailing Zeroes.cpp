#include<bits/stdc++.h>
using namespace std;

int trailingZeroes(int n) {
    if(n==0) return 0;
    int ans=0,x=5;
    while(n/x > 0){
        ans+=n/x;
        x*=5;
    }
    return ans;
}

int main(){
    int n=100;
    cout<<trailingZeroes(n);
    return 0;
}