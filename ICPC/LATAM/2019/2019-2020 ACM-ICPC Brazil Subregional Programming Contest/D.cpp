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

int d[100010];
int idx[100010];

int leafn = 0;

pair<int,int> depth(int n, vector<vector<int>>& adyl){
    pair<int,int> ans = {0,n};
    for(auto child : adyl[n]){
        auto [dd, iidx] = depth(child, adyl);  
        if( dd > ans.first) ans = {dd , iidx};
    }
    if(ans.second == n) leafn++;
    ans.first++;
    d[n] = ans.first;
    idx[n] = ans.second;
    return ans;
}


int main()
{
    int n, k;
    cin>>n>>k;



    int parents[n+1]{0};
    vector<vector<int>> adyl(n+1, vector<int>());
    parents[1] = 1;
    for(int x = 2; x <= n; x++){
        int parent;
        cin>>parent;
        parents[x] = parent;
        adyl[parent].pb(x);
    }

    auto [dd, iidx] = depth(1, adyl);
    d[1] = dd;
    idx[1] = iidx;



    set<pair<int,int>> nodes;

    for(int x = 1; x <=n; x++){
        nodes.insert({d[x], x});
    }

    int ans = 0;
    for(int x = 0; x < k; x++){
        if(nodes.empty()) break;
        auto [ maxd, node] = *(--nodes.end());
        ans++;
        int leaf = idx[node];
        while(leaf != node){
            ans++;
            nodes.erase({d[leaf], leaf});
            leaf = parents[leaf];  
        }
        nodes.erase({d[node], node});
    }


    cout<<ans<<"\n";



    

    

    
 
    



}   