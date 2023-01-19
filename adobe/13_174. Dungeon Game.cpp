#include<bits/stdc++.h>
using namespace std;

int func(vector<vector<int>>& dungeon, vector<vector<int>>& dp, int i=0, int j=0){
    int n=dungeon.size(),m=dungeon[0].size();
    if(i==n || j==m) return 1e9;
    if(dp[i][j] != -1) return dp[i][j];
    if(i==n-1 && j==m-1){
        return (dungeon[i][j]<=0)?(-dungeon[i][j]+1):1;
    }
    int r=func(dungeon,dp,i+1,j);
    int c=func(dungeon,dp,i,j+1);
    int x=min(r,c)-dungeon[i][j];
    return dp[i][j]=(x<=0)?1:x;
}
int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int n=dungeon.size(),m=dungeon[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return func(dungeon,dp);
}

int main(){

    vector<vector<int>> dungeon={{-2,-3,3},{-5,-10,1},{10,30,-5}};
    cout<<calculateMinimumHP(dungeon);

    return 0;
}