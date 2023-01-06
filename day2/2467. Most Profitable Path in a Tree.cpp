#include<bits/stdc++.h>
using namespace std;

void dfs1(vector<vector<int>>& graph, int vertex, int par, vector<int>& p){
    p[vertex]=par;
    for(auto child: graph[vertex]){
        if(child == par)continue;
        dfs1(graph,child,vertex,p);
    }
}

int dfs2(vector<vector<int>>& graph, int vertex, int par, vector<int>& p, int bob,vector<int>&amount){
    int ans=0,a=amount[vertex],b=amount[bob];
    if(vertex == bob){
        ans+=amount[vertex]/2;
        amount[vertex]=0;
    }else{
        ans+=amount[vertex];
        amount[vertex]=0;
        amount[bob]=0;
    }
    int x=INT_MIN,z=0;
    for(auto child: graph[vertex]){
        if(child == par) continue;
        z=1;
        x=max(x,dfs2(graph,child,vertex,p,p[bob],amount));
    }
    amount[vertex]=a;
    amount[bob]=b;
    if(z==0) x=0;
    return x+ans;
}

int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
    vector<vector<int>> graph(amount.size());
    for(auto p: edges){
        graph[p[0]].push_back(p[1]);
        graph[p[1]].push_back(p[0]);
    }
    vector<int> par(amount.size(),-1);
    dfs1(graph,0,0,par);
    int ans=dfs2(graph,0,0,par,bob,amount);
    return ans;
}

int main(){

    vector<vector<int>> edges={{0,1},{1,2},{1,3},{3,4}};
    int bob=3;
    vector<int> amount={-2,4,2,-4,6};
    cout<<mostProfitablePath(edges,bob,amount);

    return 0;
}