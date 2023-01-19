#include<bits/stdc++.h>
using namespace std;

vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
    vector<int> ans;
    for(auto p: queries){
        vector<pair<string,int>> v;
        int i=0;
        for(auto x: nums){
            v.push_back({x.substr(x.size()-p[1]),i});
            i++;
        }
        sort(v.begin(),v.end());
        ans.push_back(v[p[0]-1].second);
    }
    return ans;
}