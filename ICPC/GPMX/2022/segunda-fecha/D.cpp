#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, long long> > grafo[100001];
bitset<100001> visitado;

struct pos{
    int nodo;
    int d;
    long long c;

    pos(int n, int d, long long c) : nodo(n), d(d), c(c){}

    const bool operator<(const pos &b) const {
        if(d == b.d) return b.c < c;
        return b.d < d;
    }
};


long long prim(){
    priority_queue<pos> cola;
    cola.push(pos(1, 0, 0));
    long long ans = 0;

    while(cola.size()){
        pos act = cola.top();
        cola.pop();

        if(visitado[act.nodo]) continue;
        visitado[act.nodo] = true;

        ans += act.d * act.c;

        for(pair<int, long long> it : grafo[act.nodo]){
            cola.push(pos(it.first, act.d + 1, it.second));
        }
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        grafo[a].push_back({b, c});
        grafo[b].push_back({a, c});
    }

    cout << prim();
}