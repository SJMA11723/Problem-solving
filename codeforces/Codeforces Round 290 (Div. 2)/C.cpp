/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> graph[26];
int vis[26];

bool topo_sort(int node, vector<int> &topo_ord){
    if(vis[node]) return vis[node] == 2;
    vis[node] = 1;
    bool res = true;
    for(int v : graph[node]) res = res && topo_sort(v, topo_ord);
    topo_ord.push_back(node);
    vis[node] = 2;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    string names[n];
    for(int i = 0; i < n; ++i) cin >> names[i];

    bool ok = true;
    set<pair<int, int>> edges;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            int len = min(names[i].size(), names[j].size());
            for(int k = 0; k < len; ++k){
                if(names[i][k] == names[j][k]){
                    if(k + 1 == len && len == names[j].size()) ok = false;
                    continue;
                }
                edges.insert({names[i][k] - 'a', names[j][k] - 'a'});
                break;
            }
        }
    }

    for(auto [from, to] : edges)
        graph[from].push_back(to);

    vector<int> topo_ord;
    int t = 1;
    for(int i = 0; i < 26; ++i){
        if(vis[i]) continue;
        ok = ok && topo_sort(i, topo_ord);
    }

    if(ok){
        reverse(topo_ord.begin(), topo_ord.end());
        for(char c : topo_ord) cout << char(c + 'a');
        cout << '\n';
    } else cout << "Impossible\n";
}
