#include<bits/stdc++.h>
using namespace std;

const int M=1e9+7;

vector<long long> bfs(vector<vector<pair<int,long long>>>& graph, int n){
    set<pair<long long,int>> s;
    vector<long long> dis(n,-1);
    s.insert({0,0});
    while(!s.empty()){
        auto p=*s.begin();
        s.erase(s.begin());
        if(dis[p.second] != -1)continue;
        dis[p.second]=p.first;
        for(auto child: graph[p.second]){
            s.insert({child.second+p.first,child.first});
        }
    }
    return dis;
}

int dfs(vector<vector<int>>&graph, vector<long long>& dp, int vertex, int n){
    if(dp[vertex] != -1) return dp[vertex];
    if(vertex == n-1) return 1;
    long long c=0;
    for(auto child: graph[vertex]){
        c=(c+dfs(graph,dp,child,n))%M;
    }
    return dp[vertex]=(int)c;
}

int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int,long long>>> graph(n);
    for(auto p: roads){
        graph[p[0]].push_back({p[1],p[2]});
        graph[p[1]].push_back({p[0],p[2]});
    }
    vector<long long> dis=bfs(graph,n);
    vector<long long> dp(n,-1);
    vector<vector<int>> graph1(n);
    for(auto p: roads){
        if(dis[p[0]]+p[2]==dis[p[1]])
        graph1[p[0]].push_back(p[1]);
        if(dis[p[1]]+p[2]==dis[p[0]])
        graph1[p[1]].push_back(p[0]);
    }
    return dfs(graph1, dp, 0, n);
}

int main(){

    int n=7;
    vector<vector<int>> roads={{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    cout<<countPaths(n,roads);

    return 0;
}