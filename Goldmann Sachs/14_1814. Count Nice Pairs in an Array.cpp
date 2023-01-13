#include<bits/stdc++.h>
using namespace std;

int modInverse(int a, int m){
    int m0 = m;
    int y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}
int rev(int x){
    int c=0;
    while(x){
        c=c*10+x%10;
        x/=10;
    }
    return c;
}

int countNicePairs(vector<int>& nums) {
    const int M=1e9+7;
    map<int,long long> m;
    for(auto x: nums){
        m[x-rev(x)]++;
    }
    int ans=0;
    for(auto p: m){
        ans=(ans+((((p.second-1)*p.second)%M)*modInverse(2,M))%M)%M;
    }
    return ans;
}

int main(){

    vector<int> nums={42,11,1,97};
    cout<<countNicePairs(nums);

    return 0;
}