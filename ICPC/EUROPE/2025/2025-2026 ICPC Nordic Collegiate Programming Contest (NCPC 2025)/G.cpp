// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int pokever[100010];
bool vis[100010];
int ver = 1;
int dfs(int node, vector<int>* adyl, int k){
    if(vis[node]) return 0;
    if(ver > k) ver = 1;
    
    vis[node] = true;
    pokever[node] = ver;
    ver++;
    
    int sz = 1;
    for(auto child : adyl[node]){
        sz+=dfs(child, adyl, k);
    }
    return sz;
}   
int main() {
int n,m,k;
    cin>>n>>m>>k;


    vector<int> adyl[n+1];
    for(int x = 0; x < m; x++){
        int u,v;
        cin>>u>>v;
        adyl[u].push_back(v);
        adyl[v].push_back(u);
    }
    bool flag = true;
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        ver = 1;
        int count = dfs(i, adyl, k);
        if(count < k){
            flag = false;
            break;
        }
    }

    if(!flag) cout<<"impossible\n";
    else {
        for(int i = 1; i <= n; i++) cout<<pokever[i]<<" ";
        cout<<"\n";
    }
    
}