#include<bits/stdc++.h>
using namespace std;

int maxRotateFunction(vector<int>& nums) {
    int sum=0,ans=0,x;
    for(int i=0; i<nums.size(); i++){
        sum+=nums[i];
        ans+=i*nums[i];
    }
    x=ans;
    for(int i=nums.size()-1; i>0; i--){
        x+=sum-nums[i]*nums.size();
        ans=max(ans,x);
    }
    return ans;
}

int main(){

    vector<int> nums={4,3,2,6};
    cout<<maxRotateFunction(nums)<<endl;

    return 0;
}