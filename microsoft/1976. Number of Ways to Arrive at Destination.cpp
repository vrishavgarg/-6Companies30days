#include<bits/stdc++.h>
using namespace std;

const int M=1e9+7;

int dfs(vector<vector<int>>& graph, int vertex, vector<int>& dp){
    if(dp[vertex] != -1) return dp[vertex];
    if(vertex == 0) return 1;
    long long c=0;
    for(auto child: graph[vertex]){
        c=(c+dfs(graph,child,dp))%M;
    }
    return dp[vertex]=(int)c;
}

int bfs(vector<vector<pair<int,int>>>& graph, int n){
    vector<vector<int>> graph1(n);
    set<pair<long long,int>> s;
    s.insert({0,0});
    while(!s.empty()){
        auto p=*s.begin();
        s.erase(s.begin());
        if(p.second == n-1) break;
        for(auto child: graph[p.second]){
            graph1[child.first].push_back(p.second);
            s.insert({(long long)child.second+p.first,child.first});
        }
    }
    vector<int> dp(n,-1);
    return dfs(graph1,n-1,dp);
}

int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int,int>>> graph(n);
    for(auto p: roads){
        graph[p[0]].push_back({p[1],p[2]});
        graph[p[1]].push_back({p[0],p[2]});
    }
    return bfs(graph,n);
}

int main(){

    int n=7;
        

    return 0;
}