#include<bits/stdc++.h>
using namespace std;

void func(vector<vector<int>>& grid, int n, int m, int x, int y, int f, int a, int b, int ans, set<int>& s){
    if(f==5){
        s.insert(ans);
        return;
    }
    if(f==1){
        int c=0;
        for(int i=y; i>=0; i--){
            if(x+2*(-i+y)<n && y+(y-i) <m){
                c+=grid[x-i+y][i];
                func(grid,n,m,x-i+y,i,2,x-i+y,y,c,s);
            }
            else break;
        }
    }else if(f==2){
        int c=0;
        for(int i=1; i<=b-y; i++){
            c+=grid[x+i][y+i];
        }
        func(grid,n,m,x+(b-y),b,3,a,b,ans+c,s);
    }else if(f==3){
        int c=0;
        for(int i=1; i<=x-a; i++){
            c+=grid[x-i][y+i];
        }
        func(grid,n,m,a,y+(x-a),4,a,b,ans+c,s);
    }else if(f==4){
        int c=0;
        for(int i=1; i<y-b; i++){
            c+=grid[x-i][y-i];
        }
        func(grid,n,m,x-(y-b),b,5,a,b,ans+c,s);
    }else return;
}

vector<int> getBiggestThree(vector<vector<int>>& grid) {
    int n=grid.size(),m=grid[0].size();
    set<int> s;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            func(grid,n,m,i,j,1,-1,-1,0,s);
        }
    }
    vector<int> ans;
    if(s.size()==1){
        ans.push_back(*s.begin());
    }else if(s.size()==2){
        ans.push_back(*next(s.begin()));
        ans.push_back(*s.begin());
    }else{
        ans.push_back(*prev(s.end()));
        ans.push_back(*prev(prev(s.end())));
        ans.push_back(*prev(prev(prev(s.end()))));
    }
    return ans;
}

int main(){

    vector<vector<int>> grid={{3,4,5,1,3},{3,3,4,2,3},{20,30,200,40,10},{1,5,5,4,1},{4,3,2,2,5}};
    vector<int> ans=getBiggestThree(grid);
    for(auto x: ans){
        cout<<x<<' ';
    }
    cout<<endl;
    

    return 0;
}