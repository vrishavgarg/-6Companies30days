#include<bits/stdc++.h>
using namespace std;

int numMatchingSubseq(string s, vector<string>& words) {
    vector<int> v(26,INT_MAX);
    int n=s.size();
    map<int,vector<int>> m;
    for(int i=n-1; i>=0; i--){
        m[i]=v;
        v[s[i]-'a']=i;
    }
    int ans=0;
    for(auto x: words){
        int a=v[x[0]-'a'];
        if(a==INT_MAX){
            continue;
        }
        int p=0;
        for(int i=1; i<x.size(); i++){
            a=m[a][x[i]-'a'];
            if(a==INT_MAX){
                p=1;
                break;
            }
        }
        if(p)continue;
        ans++;
    }
    return ans;
}

int main(){

    string s="abcde";
    vector<string> words={"a","bb","acd","ace"};
    cout<<numMatchingSubseq(s,words);

    return 0;
}