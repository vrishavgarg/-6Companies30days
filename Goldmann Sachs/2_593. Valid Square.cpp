#include<bits/stdc++.h>
using namespace std;

bool equality(double x, double y){
    return (x-y)>=(double)-0.000001 && (x-y)<=(double)0.000001;
}
bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    const double M=1e9+7;
    vector<double> slopes;
    vector<vector<int>> points={p1,p2,p3,p4};
    for(int i=0; i<4; i++){
        for(int j=i+1; j<4; j++){
            if(points[i][0] == points[j][0]){
                slopes.push_back(M);
            }else{
                double m=(double)(points[i][1]-points[j][1])/(double)(points[i][0]-points[j][0]);
                slopes.push_back(m);
            }
        }
    }
    map<int,int> m;
    for(int i=0; i<6; i++){
        for(int j=i+1; j<6; j++){
            if(equality(slopes[i],slopes[j])) m[0]++;
            else if((equality(slopes[i],M) && equality(slopes[j],(double)0))||(equality(slopes[j],M) && equality(slopes[i],(double)0))) m[-1]++;
            else if(equality(slopes[i]*slopes[j],(double)-1)) m[-1]++;
            else{
                if(equality(slopes[i],M) || equality(slopes[j],M)){
                    if(!equality(slopes[i],(double)1) && !equality(slopes[j],(double)1) && !equality(slopes[i],(double)-1) && !equality((double)slopes[j],-1)) return 0;
                    m[1]++;
                    continue;
                }
                double s=(slopes[i]-slopes[j])/(1+slopes[i]*slopes[j]);
                if(equality(s,(double)1) || equality(s,(double)-1))m[1]++;
                else return 0;
            }
        }
    }
    return m[1]==8 && m[-1]==5 && m[0]==2;
}

int main(){

    vector<int> p1={0,0},p2={1,1},p3={1,0},p4={0,1};
    cout<<validSquare(p1,p2,p3,p4);

    return 0;
}