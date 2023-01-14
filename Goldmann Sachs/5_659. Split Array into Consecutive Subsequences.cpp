#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& nums) {
    map<int,int> m1,m2;
    for(auto x: nums){
        m1[x]++;
    }
    for(auto x: nums){
        if(m1[x] == 0) continue;
        if(m2[x] > 0){
            m2[x]--;
            m2[x+1]++;
            m1[x]--;
        }else if(m1[x]>0 && m1[x+1]>0 && m1[x+2]>0){
            m1[x]--;
            m1[x+1]--;
            m1[x+2]--;
            m2[x+3]++;
        }else return false;
    }
    return true;
}

int main(){

    vector<int> nums={1,2,3,4,5};
    cout<<isPossible(nums);

    return 0;
}