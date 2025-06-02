/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<int> graph[n];
    int in_deg[n] = {}, out_deg[n] = {};
    for(int i = 0; i < n; ++i){
        int k; cin >> k;
        while(k--){
            int v; cin >> v; v--;
            graph[i].push_back(v);
            out_deg[i]++;
            in_deg[v]++;
        }
    }

    int cnt_vis = 0;
    int cur = -1;
    for(int i = 0; i < n; ++i)
    if(in_deg[i] == 0){
        cur = i;
        break;
    }


    bool vis[n] = {};
    while(!vis[cur]){
        cnt_vis++;
        vis[cur] = true;
        for(int v : graph[cur]){
            if(in_deg[v] == 1){
                cur = v;
            }
            in_deg[v]--;
        }
    }
    cout << (cnt_vis == n) << '\n';
}
