#include<bits/stdc++.h>
using namespace std;

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    vector<pair<int,int>> v;
    for(int i=0; i<profits.size(); i++){
        v.push_back({capital[i],profits[i]});
    }
    sort(v.begin(), v.end());
    multiset<int> s;
    int i=0;
    while(k--){
        while(i<v.size() && v[i].first <= w){
            s.insert(v[i].second);
            i++;
        }
        if(s.size()>0){
            w+=*prev(s.end());
            s.erase(prev(s.end()));
        }
    }
    return w;
}

int main(){

    int k=2,w=0;
    vector<int> profit={1,2,3},capital={0,1,1};
    cout<<findMaximizedCapital(k,w,profit,capital);

    return 0;
}