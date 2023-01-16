#include<bits/stdc++.h>
using namespace std;

int magicalString(int n) {
    if(n==1 || n==2 || n==3)return 1;
    vector<int> v(n,0);
    v[0]=1;
    v[1]=2;
    v[2]=2;
    int i=2,j=3,p=1,ans=1;
    for(; j<n; ){
        if(v[i]==1){
            v[j]=p;
            j++;
            if(p==1) ans++;
        }else{
            v[j]=p;
            j++;
            if(p==1) ans++;
            if(j<n){
                v[j]=p;
                j++;
                if(p==1) ans++;
            }
        }
        i++;
        p=(p%2)+1;
    }
    return ans;
}

int main(){

    int n=6;
    cout<<magicalString(n);

    return 0;
}