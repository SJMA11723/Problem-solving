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
 
 
pair<ll,ll> lucky(int l, int r, int k){
    int len = r-l+1;
    if((len) < k) return {0,0};
    int m = (l+r)/2;
 
    if(len %2 == 0){
        auto[freq, sum] = lucky(l,m,k);
        if(freq){
            return {2*freq, (sum)+((ll)m*freq+sum)};
        }
        else{
            return {2*freq, sum};
        }
    }
    else{
        auto[freq, sum] = lucky(l,m-1,k);
        if(freq){
            return {1+2*freq, (sum) + (m) +((ll)m*freq+sum)};
        }
        else{
            return {1+ 2*freq, m + sum};
        }       
    }
}
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, c;
    cin>>n>>c;
    set<int> s;
    for(int x = 1; x<=n; x++)s.insert(x);

    for(int x = 0; x <c; x++){
        int t;
        cin>>t;
        s.erase(t);
    }

    if(s.empty()) cout<<"*\n";
    else{
        for(auto x : s){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}