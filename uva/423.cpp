/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to, w;
};

int bellman_ford(int s, int n, vector<edge> &edges){
    vector<int> d(n, INT_MAX);
    vector<int> P(n, -1);
    d[s] = 0;
    for(int i = 1; i < n; ++i){
        for(edge &e : edges){
            if(d[e.from] == INT_MAX) continue;
            if(d[e.from] + e.w < d[e.to]){
                d[e.to] = d[e.from] + e.w;
                P[e.to] = e.from;
            }
        }
    }

    vector<bool> out(n);
    for(int p : P) if(p != -1) out[p] = true;
    int res = 0;
    for(int i = 0; i < n; ++i) res = max(res, d[i] * !out[i]);

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<edge> edges;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < i; ++j){
            string s; cin >> s;
            if(s == "x") continue;
            int w = stoi(s);
            edges.push_back({i, j, w});
            edges.push_back({j, i, w});
        }
    }

    cout << bellman_ford(0, n, edges) << '\n';
}
