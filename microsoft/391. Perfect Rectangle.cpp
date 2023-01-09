#include<bits/stdc++.h>
using namespace std;

bool isRectangleCover(vector<vector<int>>& rectangles) {
    map<pair<int,int>,int> m;
    for(auto vec: rectangles){
        m[{vec[0],vec[1]}]++;
        m[{vec[2],vec[3]}]++;
        m[{vec[0],vec[3]}]--;
        m[{vec[2],vec[1]}]--;
    }
    int c=0;
    for(auto p: m){
        if(abs(p.second) == 1){
            c++;
        }else if(abs(p.second)!=1 && abs(p.second)!=0){
            return 0;
        }
    }
    return c==4;
}

int main(){

    vector<vector<int>> rectangles={{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}};
    cout<<isRectangleCover(rectangles);

    return 0;
}