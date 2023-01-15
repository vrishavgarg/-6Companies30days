#include<bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int>& nums) {
    multiset<int> s1,s2;
    for(int i=0; i<nums.size(); i++){
        s1.insert(nums[i]);
    }
    bool p=0;
    for(int i=0; i<nums.size(); i++){
        s1.erase(nums[i]);
        if(s2.lower_bound(nums[i])!= s2.begin() && s2.size()!=0 && s1.upper_bound(nums[i]) != s1.end())return 1;
        s2.insert(nums[i]);
    }
    return 0;
}

int main(){

    vector<int> nums={1,2,3,4,5};
    cout<<increasingTriplet(nums);

    return 0;
}