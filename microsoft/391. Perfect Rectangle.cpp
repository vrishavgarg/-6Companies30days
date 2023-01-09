#include<bits/stdc++.h>
using namespace std;

bool isRectangleCover(vector<vector<int>>& rectangles) {
    int s=0,x1=INT_MAX,x2=INT_MIN,y1=INT_MAX,y2=INT_MIN;
    set<pair<int,int>> m,m1;
    for(auto vec: rectangles){
        x1=min(x1,vec[0]);
        y1=min(y1,vec[1]);
        x2=max(x2,vec[2]);
        y2=max(y2,vec[3]);
        s+=(vec[2]-vec[0])*(vec[3]-vec[1]);
        m.insert({vec[1],vec[3]});
        m1.insert({vec[0],vec[2]});
    }
    if((x2-x1)*(y2-y1) == s){
        int a=-1,p=0,b=-1;
        for(auto x: m){
            if(a==-1){
                b=x.first;
                a=x.second;
            }else{
                if(a<x.first){
                    p=1;
                    break;
                }
                a=x.second;
            }
        }
        if(a!=y2 && b!=y1)p=1;
        a=-1;
        b=-1;
        for(auto x: m1){
            if(a==-1){
                a=x.second;
            }else{
                if(a<x.first){
                    p=1;
                    break;
                }
                a=x.second;
            }
        }
        if(a!=x2 && b!=x1)p=1;
        if(p) return 0;
        return 1;
    }else return 0;
}

int main(){

    vector<vector<int>> rectangles={{0,0,2,2},{1,1,3,3},{2,0,3,1},{0,3,3,4}};
    cout<<isRectangleCover(rectangles)<<endl;

    return 0;
}