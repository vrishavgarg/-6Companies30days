#include<bits/stdc++.h>
using namespace std;

int stringToInt(string& str){
    int x=0,p=0;
    for(auto c: str){
        if(c=='-'){
            p=1;
            continue;
        }
        if(c=='+') continue;
        x=x*10+(c-'0');
    }
    if(p) return -x;
    return x;
}

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for(auto str: tokens){
        if(str[0]=='+'  && str.size() == 1){
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            st.push(y+x);
        }else if(str[0]=='-' && str.size() == 1){
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            st.push(y-x);
        }else if(str[0]=='/'){
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            st.push(y/x);
        }else if(str[0]=='*'){
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            st.push(y*x);
        }else{
            st.push(stringToInt(str));
        }
    }
    return st.top();
}

int main(){

    vector<string> tokens={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout<<evalRPN(tokens)<<endl;

    return 0;
}