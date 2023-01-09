#include<bits/stdc++.h>
using namespace std;

int gcd(int y, int x){
    if(y%x == 0){
        return x;
    }else return gcd(x,y%x);
} 

int minOperations(vector<int>& nums, vector<int>& numsDivide) {
    int x=numsDivide[0];
    for(int i=1; i<numsDivide.size(); i++){
        x=gcd(x,numsDivide[i]);
    }
    sort(nums.begin(), nums.end());
    int i=0;
    for(; i<nums.size(); i++){
        if(x%nums[i] == 0){
            break;
        }
    }
    if(i==nums.size()) return -1;
    return i;
}

int main(){

    vector<int> nums={2,3,2,4,3},numsDivide={9,6,9,3,15};
    cout<<minOperations(nums,numsDivide);

    return 0;
}