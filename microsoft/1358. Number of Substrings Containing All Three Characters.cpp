#include<bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    int n=s.size(),x=n,y=n,z=n;
    vector<int> a(n);
    for(int i=n-1; i>=0; i--){
        if(s[i]=='a')x=i;
        if(s[i]=='b')y=i;
        if(s[i]=='c')z=i;
        a[i]=max({x,y,z});
    }
    int ans=0;
    for(int i=0; i<n; i++){
        ans+=n-a[i];
    }
    return ans;
}

int main(){
    string s="abcabc";
    cout<<numberOfSubstrings(s);

    return 0;
}