#include<bits/stdc++.h>
using namespace std;

string longestPrefix(string s) {
    int n=s.size();
    string ans="";
    int i=0,j=1;
    vector<int> a(n,0);
    while(j<n){
        if(s[i]==s[j]){
            a[j]=i+1;
            i++;
            j++;
        }else if(i > 0){
            i=a[i-1];
        }else{
            j++;
        }
    }
    for(int k=0; k<i; k++){
        ans.push_back(s[k]);
    }
    return ans;
}

int main(){
    
    string s="ababab";
    cout<<longestPrefix(s);
    
    return 0;
}