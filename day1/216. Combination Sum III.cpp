#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
void combination(vector<int>& a, int k, int n, int x){
    if(k == 0 && n == 0){
        ans.push_back(a);
        return;
    }
    if(k == 0 || n == 0 || x==0) return;
    if(n-x >= 0){
        a.push_back(x);
        combination(a,k-1,n-x,x-1);
        a.pop_back();
    }
    combination(a,k,n,x-1);
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> a;
    combination(a,k,n,9);
    return ans;
}

int main(){

    int n=1,k=4;
    vector<vector<int>> ans=combinationSum3(k,n);

    for(auto x: ans){
        for(auto y: x){
            cout<<y<<' ';
        }
        cout<<endl;
    }

    return 0;
}