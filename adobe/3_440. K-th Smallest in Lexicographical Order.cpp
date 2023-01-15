#include<bits/stdc++.h>
using namespace std;

int findKthNumber(int n, int k) {
    int ans=1;
    for(k--;k>0;){
        int c=0;
        for(long long i=(long long)ans,j=i+1; i<=n; i*=10,j*=10){
            c+=(int)(min((long long)n+1,j)-i);
        }
        if(k>=c){
            ans++;
            k-=c;
        }else{
            ans*=10;
            k--;
        }
    }
    
    return ans;
}

int main(){

    int n=13,k=2;
    cout<<findKthNumber(n,k);

    return 0;
}