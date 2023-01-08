#include<bits/stdc++.h>
using namespace std;

void update(vector<long long>& bit, int idx, long long x){
    for(; idx<1e5; idx=(idx|(idx+1))){
        bit[idx]+=x;
    }
}

long long sum(vector<long long>& bit, int idx){
    long long x=0;
    for(; idx>=0; idx=(idx&(idx+1))-1){
        x+=bit[idx];
    }
    return x;
}

long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
    int M=1e5;
    vector<long long> bit(M,0);
    long long ans=0;
    for(int i=nums2.size()-1; i>=0; i--){
        ans+=sum(bit,M-1)-sum(bit,nums1[i]-nums2[i]-diff-1+(M/2));
        update(bit,nums1[i]-nums2[i]+(M/2),1);
    }
    return ans;
}

int main(){

    vector<int> nums1={3,2,5},nums2={2,2,1};
    int diff=1;
    cout<<numberOfPairs(nums1,nums2,diff)<<endl;

    return 0;
}