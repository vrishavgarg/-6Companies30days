#include<bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>>& points) {
    if(points.size() == 1) return 1;
    const int M=1e9+7;
    map<pair<double,double>,set<pair<int,int>>> x;
    for(int i=0; i<points.size(); i++){
        for(int j=i+1; j<points.size(); j++){
            double m,c;
            if(points[i][0] == points[j][0]){
                m=(double)M;
                c=points[i][0];
            }else{
                m=(double)(points[i][1]-points[j][1])/(double)(points[i][0]-points[j][0]);
                c=points[i][1]-m*points[i][0];
            }
            x[{m,c}].insert({points[i][0],points[i][1]});
            x[{m,c}].insert({points[j][0],points[j][1]});
        }
    }
    int ans=0;
    for(auto y: x){
        ans=max(ans,(int)y.second.size());
    }
    return ans;
}

int main(){

    vector<vector<int>> points={{1,1},{2,2},{3,3}};
    cout<<maxPoints(points)<<endl;

    return 0;
}