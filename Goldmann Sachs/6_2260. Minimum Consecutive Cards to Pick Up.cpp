#include<bits/stdc++.h>
using namespace std;

int minimumCardPickup(vector<int>& cards) {
    map<int,int> m;
    int ans=INT_MAX;
    for(int i=0; i<cards.size(); i++){
        if(m[cards[i]] != 0){
            ans=min(ans,i+2-m[cards[i]]);
        }
        m[cards[i]]=i+1;
    }
    if(ans==INT_MAX)return -1;
    return ans;
}

int main(){

    vector<int> cards={3,4,2,3,4,7};
    cout<<minimumCardPickup(cards);

    return 0;
}