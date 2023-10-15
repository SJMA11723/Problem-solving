/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 1000001

using namespace std;

struct edge{
    int to;
    long double d, v;
};

vector<edge> grafo[MAXN];
vector<char> visitado(MAXN);
long double dist[MAXN];

struct pos{
    int i;
    long double t;

    bool operator<(const pos &b) const {
        return t > b.t;
    }
};

long double dijkstra(int a, int b, long double incr){
    fill(dist, dist + MAXN, 1e50);
    fill(visitado.begin(), visitado.end(), false);

    priority_queue<pos> q;
    q.push({a, 0});
    dist[a] = 0;

    while(!q.empty()){
        pos act = q.top();
        q.pop();

        if(visitado[act.i]) continue;
        if(act.i == b) return act.t;
        visitado[act.i] = true;

        //cout << "llega a " << act.i << " con tiempo " << act.t << '\n';

        for(edge e : grafo[act.i]){
            long double c = e.d / (e.v + incr);
            if(dist[e.to] < dist[act.i] + c) continue;

            //cout << "va a " << e.to

            dist[e.to] = dist[act.i] + c;
            pos np{e.to, dist[e.to]};
            q.push(np);
        }
    }

    return dist[b];
}

long double tiempo(vector<edge> &camino, long double incr){
    long double t = 0;
    for(edge e : camino)
        t += e.d / (e.v + incr);
    return t;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    long double t;
    cin >> n >> m >> t;
    for(int i = 0; i < m; ++i){
        int a, b;
        long double l, v;
        cin >> a >> b >> l >> v;
        grafo[a].push_back({b, l, v});
        grafo[b].push_back({a, l, v});
    }

    if(dijkstra(1, n, 0) <= t){
        cout << "0\n";
        return 0;
    }

    long double ini = 0, fin = 1;
    while(dijkstra(1, n, fin) > t) fin *= 2;

    while( fabs(fin - ini) > (1e-10) ){
        long double mitad = (ini + fin) / 2;
        if(dijkstra(1, n, mitad) <= t) fin = mitad;
        else ini = mitad;
    }
    cout << fixed << setprecision(8) << ini << '\n';
}
