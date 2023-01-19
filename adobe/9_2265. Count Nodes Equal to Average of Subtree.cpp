#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int,pair<int,int>> dfs(TreeNode* vertex){
        int a=vertex->val,b=1,c=0;
        if(vertex->left){
            pair<int,pair<int,int>> p=dfs(vertex->left);
            c+=p.first;
            a+=p.second.first;
            b+=p.second.second;
        }
        if(vertex->right){
            pair<int,pair<int,int>> p=dfs(vertex->right);
            c+=p.first;
            a+=p.second.first;
            b+=p.second.second;
        }
        if(vertex->val == (a/b)) c++;
        return make_pair(c,make_pair(a,b));
    }
    int averageOfSubtree(TreeNode* root) {
        return dfs(root).first;
    }
};