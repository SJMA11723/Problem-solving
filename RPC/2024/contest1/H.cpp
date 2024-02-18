/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 101

using namespace std;

struct edge{
    int to;
    long long c;
    int idx;
};

struct pos{
    int from;
    long long c;
    const bool operator<(const pos &b)const{
        return c > b.c;
    }
};

vector<edge> grafo[MAXN];

int dijkstra(int a, int b, int m){
    long long dist[MAXN];
    bool visitado[MAXN];
    fill(dist, dist + MAXN, LLONG_MAX);
    memset(visitado, 0, sizeof(visitado));

    vector<edge> prev[MAXN];
    priority_queue<pos> pq;
    pq.push(pos{a, 0});
    dist[a] = 0;

    while(!pq.empty()){
        pos act = pq.top();
        pq.pop();

        if(visitado[act.from]) continue;
        visitado[act.from] = true;

        for(edge &e : grafo[act.from]){
            int ndist = dist[act.from] + e.c;
            if(dist[e.to] < ndist) continue;

            if(ndist < dist[e.to])
                prev[e.to].clear();

            prev[e.to].push_back({act.from, e.c, e.idx});

            dist[e.to] = dist[act.from] + e.c;
            pq.push(pos{e.to, dist[e.to]});
        }
    }

    int sum = 0;
    bool ap[m] = {};
    memset(visitado, 0, sizeof(visitado));
    queue<int> q;
    q.push(b);
    while(q.size()){
        int act = q.front();
        q.pop();

        if(visitado[act]) continue;
        visitado[act] = true;

        for(edge &e : prev[act]){
            if(!visitado[e.to]) q.push(e.to);

            if(!ap[e.idx]){
                ap[e.idx] = true;
                sum += e.c;
            }
        }
    }

    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int sum = 0;
    for(int i = 0; i < m; ++i){
        int l, r, c;
        cin >> l >> r >> c;
        grafo[l].push_back({r, c, i});
        grafo[r].push_back({l, c, i});
        sum += c;
    }

    cout << sum - dijkstra(a, b, m) << '\n';
}
