#include<bits/stdc++.h>
using namespace std;

int func(int numArrows, vector<int>& aliceArrows, vector<vector<int>>& dp, int idx){
    if(numArrows == 0 || idx==-1) return 0;
    if(dp[numArrows][idx] != -1) return dp[numArrows][idx];
    int c=func(numArrows,aliceArrows,dp,idx-1);
    if(numArrows-aliceArrows[idx]-1 >= 0){
        c=max(c,idx+func(numArrows-aliceArrows[idx]-1,aliceArrows,dp,idx-1));
    }
    return dp[numArrows][idx]=c;
}

void func2(int x, vector<int>& aliceArrows, vector<int>& bobArrows, int idx, vector<int>& y, int numArrows){
    if(x==0 && numArrows>=0){
        y[0]+=numArrows;
        bobArrows=y;
        return;
    }
    if(x==0 || numArrows==0)return;
    if(idx == -1) return;
    func2(x,aliceArrows,bobArrows,idx-1,y,numArrows);
    if(bobArrows.size()>0)return;
    if(x-idx >=0 && numArrows-aliceArrows[idx]-1>=0){
        y[idx]=aliceArrows[idx]+1;
        func2(x-idx, aliceArrows, bobArrows, idx-1, y,numArrows-aliceArrows[idx]-1);
        y[idx]=0;
    }
}

vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
    vector<vector<int>> dp(numArrows+1,vector<int>(12,-1));
    int x=func(numArrows,aliceArrows,dp,11);
    vector<int> bobArrows,y(12,0);
    func2(x,aliceArrows,bobArrows,11,y,numArrows);
    return bobArrows;
}

int main(){

    int numArrows=9;
    vector<int> aliceArrows={1,1,0,1,0,0,2,1,0,1,2,0};
    vector<int> bobArrows=maximumBobPoints(numArrows,aliceArrows);
    for(auto x:bobArrows){
        cout<<x<<' ';
    }
    cout<<endl;

    return 0;
}