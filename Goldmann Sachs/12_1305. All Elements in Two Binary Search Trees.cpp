#include<bits/stdc++.h>

//Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void dfs(TreeNode* vertex, vector<int>&a){
        if(vertex == NULL) return;
        a.push_back(vertex->val);
        dfs(vertex->left,a);
        dfs(vertex->right,a);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a;
        dfs(root1,a);
        dfs(root2,a);
        sort(a.begin(),a.end());
        return a;
    }
};