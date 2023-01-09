#include<bits/stdc++.h>
using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
    const int N=2e5+10,M=1e5;
    vector<int> s(N,0);
    deque<int> d;
    for(auto x: nums){
        s[x+M]++;
        d.push_back(x);
    }
    vector<int> v;
    for(int i=0; i<N; i++){
        for(int j=0; j<s[i]; j++){
            v.push_back(i-M);
        }
    }
    int a=0;
    while(!d.empty() && v[a]==d.front()){
        a++;
        d.pop_front();
    }
    a=v.size()-1;
    while(!d.empty() && v[a]==d.back()){
        a--;
        d.pop_back();
    }
    int ans=0;
    while(!d.empty()){
        ans++;
        d.pop_front();
    }
    return ans;
}

int main(){

    vector<int> nums={2,6,4,8,10,9,15};
    cout<<findUnsortedSubarray(nums);

    return 0;
}