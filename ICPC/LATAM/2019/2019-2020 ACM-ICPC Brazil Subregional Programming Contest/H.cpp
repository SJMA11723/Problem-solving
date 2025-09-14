// Source: https://usaco.guide/general/io
 
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <map>
#define DEBUG if (deb)
#define INF 2000000000
#define LINF 2000000000000000000
bool deb = true;
using namespace std;
#define pb push_back
typedef long long ll;



int main()
{

    int v,n;
    cin>>v>>n;

    int cnt = v*n;
    int ans[9];
    for(int i = 1; i <=9; i++){
        if(cnt * i % 10 == 0) ans[i-1] = (cnt*i)/10;
        else ans[i-1] = (cnt*i)/10 + 1;
    }


    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<"\n";
 
    



}   