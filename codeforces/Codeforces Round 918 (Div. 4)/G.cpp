/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 1001

using namespace std;

struct edge{
    int to;
    int64_t c;
};

struct pos{
    int from;
    int64_t c, bike;
    const bool operator<(const pos &b)const{
        return c > b.c;
    }
};

int64_t dist[MAXN][MAXN];
bool visitado[MAXN][MAXN];

int64_t dijkstra(int a, int b, int64_t S[], vector<edge> grafo[]){
    for(int i = 0; i < MAXN; ++i) for(int j = 0; j < MAXN; ++j) dist[i][j] = LLONG_MAX;
    memset(visitado, 0, sizeof(visitado));

    priority_queue<pos> q;
    q.push(pos{a, 0, S[a]});
    dist[a][S[a]] = 0;

    while(!q.empty()){
        pos act = q.top();
        q.pop();

        if(visitado[act.from][act.bike]) continue;
        visitado[act.from][act.bike] = true;

        for(edge &e : grafo[act.from]){
            if(dist[e.to][act.bike] < act.c + e.c * act.bike) continue;

            dist[e.to][act.bike] = act.c + e.c * act.bike;
            q.push(pos{e.to, dist[e.to][act.bike], min(act.bike, S[e.to])});
        }
    }

    return *min_element(dist[b], dist[b] + MAXN);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<edge> grafo[n + 1];
        while(m--){
            int a, b, w;
            cin >> a >> b >> w;
            grafo[a].push_back({b, w});
            grafo[b].push_back({a, w});
        }

        int64_t S[n + 1];
        for(int i = 1; i <= n; ++i) cin >> S[i];
        cout << dijkstra(1, n, S, grafo) << '\n';
    }
}
