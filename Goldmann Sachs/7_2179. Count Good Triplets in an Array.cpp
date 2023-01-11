#include<bits/stdc++.h>
using namespace std;

void update(vector<long long>& bit, int idx, long long a){
    for(; idx<bit.size(); idx=idx|(idx+1)){
        bit[idx]+=a;
    }
}

long long sum(vector<long long>& bit, int idx){
    long long c=0;
    for(; idx>=0; idx=(idx&(idx+1))-1){
        c+=bit[idx];
    }
    return c;
}

long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    map<int,int> m;
    for(int i=0; i<nums1.size(); i++){
        m[nums1[i]]=i;
    }
    for(int i=0; i<nums2.size(); i++){
        nums2[i]=m[nums2[i]];
    }
    vector<long long> b1(nums1.size(),0),b2(nums1.size(),0);
    for(int i=0; i<nums1.size(); i++){
        update(b1,nums2[i],1);
    }
    long long ans=0;
    for(int i=nums2.size()-1; i>=0; i--){
        update(b1,nums2[i],-1);
        ans+=sum(b1,nums2[i]-1)*(sum(b2,nums2.size()-1)-sum(b2,nums2[i]));
        update(b2,nums2[i],1);
    }
    return ans;
}

int main(){

    vector<int> nums1={2,0,1,3},nums2={0,1,2,3};
    cout<<goodTriplets(nums1,nums2);

    return 0;
}