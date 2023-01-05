#include<bits/stdc++.h>
using namespace std;

string getHint(string secret, string guess) {
    map<char,int> m1,m2;
    int bull=0,cow=0;
    for(int i=0; i<secret.size(); i++){
        if(secret[i] == guess[i]){
            bull++;
            continue;
        }
        m1[secret[i]]++;
        m2[guess[i]]++;
    }
    for(auto p: m1){
        cow+=min(m2[p.first],p.second);
    }
    string ans;
    stack<char> st;
    if(bull == 0) st.push('0');
    while(bull){
        st.push(bull%10+'0');
        bull/=10;
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    ans.push_back('A');
    if(cow == 0) st.push('0');
    while(cow){
        st.push(cow%10+'0');
        cow/=10;
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    ans.push_back('B');
    return ans;
}

int main(){

    string secret="1",guess="0";
    cout<<getHint(secret,guess)<<endl;

    return 0;
}