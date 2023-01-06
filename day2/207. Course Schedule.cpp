#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& graph, int vertex, vector<int>& vis, int x, vector<int>& vis1){
    if(vis[vertex]!=-1){
        if(vis[vertex] == x){
            return 0;
        }else{
            return 1;
        }
    }
    if(vis1[vertex] !=- 1)return vis1[vertex];
    vis[vertex]=x;
    bool ans=1;
    for(auto child: graph[vertex]){
        ans&=dfs(graph,child,vis,x,vis1);
    }
    vis[vertex]=-1;
    return vis1[vertex]=ans;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>(0));
    for(auto p: prerequisites){
        graph[p[1]].push_back(p[0]);
    }
    vector<int> vis(numCourses,-1),vis1(numCourses,-1);
    bool ans=1;
    for(int i=0; i<numCourses; i++){
        if(vis1[i]!=-1)continue;
        ans&=dfs(graph,i,vis,i,vis1);
        if(ans==0) break;
    }
    return ans;
}

int main(){

    int numCourses=4;
    vector<vector<int>> prerequisites{{1,0},{2,0},{3,1},{3,2}};
    cout<<canFinish(numCourses,prerequisites)<<endl;

    return 0;
}