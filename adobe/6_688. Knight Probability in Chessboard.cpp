#include<bits/stdc++.h>
using namespace std;

double knightProbability(int n, int k, int row, int column) {
    vector<pair<int,int>> move={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
    vector<vector<double>> dp(n,vector<double> (n,0));
    dp[row][column]=1;
    while(k--){
        vector<vector<double>> dp1(n,vector<double> (n,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(auto x: move){
                    int a=i+x.first,b=j+x.second;
                    if(a>=0 && a<n && b>=0 && b<n){
                        dp1[a][b]+=dp[i][j]/8;
                    }
                }
            }
        }
        dp=dp1;
    }
    double ans=0;
    for(auto x: dp){
        for(auto y: x){
            ans+=y;
        }
    }
    return ans;
}

int main(){

    int n=3,k=2,row=0,column=0;
    cout<<knightProbability(n,k,row,column);

    return 0;
}