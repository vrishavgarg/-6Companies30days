#include<bits/stdc++.h>
using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    int y=0;
    if((numerator>0 && denominator<0) || (numerator<0 && denominator>0))y=1;
    numerator=abs(numerator);
    denominator=abs(denominator);
    long long x=numerator/denominator;
    string s;
    if(x==0)s.push_back('0');
    while(x){
        s.push_back(x%10 + '0');
        x/=10;
    }
    if(y) s.push_back('-');
    reverse(s.begin(),s.end());
    if(numerator%denominator == 0) return s;
    s.push_back('.');
    map<int,int> a;
    x=numerator%denominator;
    int i=s.size();
    while(x!=0 && a.find(x) == a.end()){
        a[x]=i;
        x*=10;
        s.push_back((x/denominator) +'0');
        x=x%denominator;
        i++;
    }
    if(x==0)return s;
    string ans;
    for(int i=0; i<s.size(); i++){
        if(i==a[x]){
            ans.push_back('(');
            ans.push_back(s[i]);
        }else{
            ans.push_back(s[i]);
        }
    }
    ans.push_back(')');
    return ans;
}

int main(){

    int numerator=1,denominator=2;
    cout<<fractionToDecimal(numerator,denominator);

    return 0;
}