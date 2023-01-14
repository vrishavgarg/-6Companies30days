#include<bits/stdc++.h>
using namespace std;

int stringToInt(string x){
    int c=0;
    for(int i=0; i<x.size(); i++){
        c=c*10+(x[i]-'0');
    }
    return c;
}

vector<string> invalidTransactions(vector<string>& transactions) {
    vector<vector<string>> v(transactions.size());
    int i=0;
    for(auto x: transactions){
        string a;
        for(auto c: x){
            if(c==','){
                v[i].push_back(a);
                a.clear();
                continue;
            }
            a.push_back(c);
        }
        v[i].push_back(a);
        i++;
    }
    set<int> s;
    for(int i=0; i<transactions.size(); i++){
        if(stringToInt(v[i][2]) > 1000){
            s.insert(i);
        }
    }
    for(int i=0; i<transactions.size(); i++){
        for(int j=i+1; j<transactions.size(); j++){
            if(v[i][0]==v[j][0] && abs(stringToInt(v[i][1])-stringToInt(v[j][1]))<=60 && v[i][3]!=v[j][3]){
                s.insert(i);
                s.insert(j);
            }
        }
    }
    vector<string> ans;
    for(auto x: s){
        ans.push_back(transactions[x]);
    }
    return ans;
}

int main(){

    vector<string> transactions={"alice,20,800,mtv","alice,50,100,beijing"};
    vector<string> ans=invalidTransactions(transactions);
    for(auto x: ans){
        cout<<x<<endl;
    }

    return 0;
}