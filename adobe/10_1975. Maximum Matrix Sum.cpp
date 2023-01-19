#include<bits/stdc++.h>
using namespace std;

long long maxMatrixSum(vector<vector<int>>& matrix) {
    long long c=0,k=0,s=0,m=INT_MAX;
    for(auto x: matrix){
        for(auto y: x){
            if(y<0)c++;
            else if(y==0)k++;
            s+=abs(y);
            m=min(m,(long long)abs(y));
        }
    }
    if(k>0 || c%2==0) return s;
    return s-2*m;
}

int main(){

    vector<vector<int>> matrix={{1,-1},{-1,1}};
    cout<<maxMatrixSum(matrix);

    return 0;
}