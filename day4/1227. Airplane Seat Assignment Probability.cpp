#include<bits/stdc++.h>
using namespace std;

double nthPersonGetsNthSeat(int n) {
    if(n==1)return (double)1;
    return (double)0.5;
}

int main(){

    int n=5;
    cout<<nthPersonGetsNthSeat(n);

    return 0;
}