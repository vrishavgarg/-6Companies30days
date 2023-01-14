#include<bits/stdc++.h>
using namespace std;

int peopleAwareOfSecret(int n, int delay, int forget) {
    vector<long long> dp(n+1,0);
    dp[1]=1;
    long long x=0,M=1e9+7;
    for(int i=2; i<=n; i++){
        if(i-delay > 0){
            x=(x+dp[i-delay])%M;
        }
        if(i-forget > 0){
            x=(x-dp[i-forget]+M)%M;
        }
        dp[i]=x;
    }
    long long ans=0;
    for(int i=n-forget+1; i<=n; i++){
        ans=(ans+dp[i])%M;
    }
    return (int)ans;
}

int main(){

    int n=6, delay=2, forget=4;
    cout<<peopleAwareOfSecret(n,delay,forget);

    return 0;
}