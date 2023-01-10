#include<bits/stdc++.h>
using namespace std;

int numberOfBoomerangs(vector<vector<int>>& points) {
    int ans=0;
    for(auto x: points){
        map<int,int> m;
        for(auto y: points){
            if(x==y)continue;
            int dis=abs(y[1]-x[1])*abs(y[1]-x[1])+abs(y[0]-x[0])*abs(y[0]-x[0]); 
            m[dis]++;
        }
        for(auto k: m){
            ans+=((k.second)*(k.second-1));
        }
        m.clear();
    }
    return ans;
}

int main(){

    vector<vector<int>> points={{0,0},{0,1},{0,2}};
    cout<<numberOfBoomerangs(points);

    return 0;
}