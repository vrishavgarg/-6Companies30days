#include<bits/stdc++.h>
using namespace std;

class StockPrice {
    map<int,int> m;
    multiset<int> s;
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(s.find(m[timestamp]) != s.end()){
            s.erase(s.find(m[timestamp]));
        }
        m[timestamp]=price;
        s.insert(price);
    }
    
    int current() {
        return prev(m.end())->second;
    }
    
    int maximum() {
        return *prev(s.end());
    }
    
    int minimum() {
        return *s.begin();
    }
};