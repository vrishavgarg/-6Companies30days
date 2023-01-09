#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    map<int, int> m;
    sort(nums.begin(),nums.end());
    int ma=1;
    for(int i=0; i<nums.size(); i++){
        m[nums[i]]=1;
        for(int j=0; j<i; j++){
            if(nums[i]%nums[j] == 0){
                m[nums[i]]=max(m[nums[i]],m[nums[j]]+1);
            }
        }
        ma=max(ma,m[nums[i]]);
    }
    vector<int> ans;
    int x=-1;
    for(int i=nums.size()-1; i>=0; i--){
        if(m[nums[i]] == ma && x == -1){
            ans.push_back(nums[i]);
            ma--;
            x=nums[i];
        }else if(m[nums[i]] == ma && x!=-1 && x%nums[i] == 0){
            ans.push_back(nums[i]);
            ma--;
            x=nums[i];
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){

    vector<int> nums={1,2,4,8};
    vector<int> ans=largestDivisibleSubset(nums);
    for(auto x: ans){
        cout<<x<<' ';
    }
    cout<<endl;

    return 0;
}