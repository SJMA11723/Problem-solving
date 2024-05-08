#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to;
    int w;
};

vector<int> bellman_ford(int s, int n, vector<edge> &edges){
    vector<int> d(n + 1, INT_MAX);
    d[s] = 0;

    for(int i = 0; i < n - 1; ++i){
        for(edge &e : edges){
            if(d[e.from] == INT_MAX) continue;

            if(d[e.to] > d[e.from] + e.w){
                d[e.to] = d[e.from] + e.w;
            }
        }
    }

    return d;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<edge> edges;
    for(int i = 0; i < m; ++i){
        int s, e, a;
        char t;
        cin >> s >> e >> t >> a;
        edges.push_back({s, e, (t == 'b' ? a : -a)});
    }

    vector<int> d = bellman_ford(1, n, edges);

    for(int i = 1; i <= n; ++i){
        if(d[i] < 0) cout << i << '\n';
    }
}
