#include<bits/stdc++.h>
using namespace std;

int maximumGood(vector<vector<int>>& statements) {
    int ans=0;
    for(int i=1; i<1<<statements.size(); i++){
        int p=0;
        for(int j=0; j<statements.size(); j++){
            if((i&(1<<j)) == 0) continue;
            for(int k=0; k<statements.size(); k++){
                if((i&(1<<k)) && statements[j][k] == 0){
                    p=1;
                    break;
                }else if(!(i&(1<<k)) && statements[j][k] == 1){
                    p=1;
                    break;
                }
            }
            if(p) break;
        }
        if(p==0){
            int n=i,c=0;
            while(n){
                c+=n%2;
                n/=2;
            }
            ans=max(ans,c);
        }
    }
    return ans;
}

int main(){

    vector<vector<int>> statements={{2,1,2},{1,2,2},{2,0,2}};
    cout<<maximumGood(statements);

    return 0;
}