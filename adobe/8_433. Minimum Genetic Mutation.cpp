#include<bits/stdc++.h>
using namespace std;

int func(string startGene, string endGene, set<string>& s){
    int a=0;
    for(int i=0; i<8; i++){
        if(startGene[i]!=endGene[i])a++;
    }
    if(a==1)return 1;
    if(s.size() == 0) return 1000;
    int c=1000;
    set<string> s1=s;
    for(auto x: s1){
        int a=0;
        for(int i=0; i<8; i++){
            if(x[i]!=endGene[i])a++;
        }
        if(a==1){
            s.erase(x);
            c=min(c,1+func(startGene,x,s));
            s.insert(x);
        }
    }
    return c;
} 
int minMutation(string startGene, string endGene, vector<string>& bank) {
    if(startGene==endGene)return 0;
    if(find(bank.begin(),bank.end(),endGene) == bank.end()) return -1;
    set<string> s;
    for(auto x: bank){
        if(endGene == x)continue;
        s.insert(x);
    }
    int c=func(startGene,endGene,s);
    if(c>bank.size())return -1;
    return c;
}

int main(){

    string startGene="AACCGGTT",endGene="AACCGGTA";
    vector<string> bank={"AACCGGTA"};
    cout<<minMutation(startGene,endGene,bank);

    return 0;
}