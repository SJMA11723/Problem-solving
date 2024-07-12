/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct dsu{
    vector<int> RA, P;

    dsu(int n){
        RA.resize(n + 10);
        P.resize(n + 10);
        for(int i = 0; i <= n; ++i){
            RA[i] = 1;
            P[i] = i;
        }
    }

    void reset(int n){
        for(int i = 0; i <= n; ++i){
            RA[i] = 1;
            P[i] = i;
        }
    }

    int root(int x){
        return (x == P[x] ? x : P[x] = root(P[x]));
    }

    void join(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;

        if(RA[x] >= RA[y]) swap(x, y);
        RA[y] += RA[x];
        P[x] = y;
    }
};

struct edge{
    int from, to;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, d; cin >> n >> m >> d;
    vector<edge> edges;
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        edges.push_back({min(a, b), max(a, b)});
    }

    bool used[m] = {};
    dsu mset(n);
    for(int i = 0; i < m; ++i){ /// conecta componentes sin 1
        edge &e = edges[i];
        if(mset.root(e.from) == mset.root(e.to)) continue;
        if(e.from == 1) continue;

        mset.join(e.from, e.to);
    }

    int deg_1 = 0;
    for(int i = 0; i < m; ++i){ /// conecta 1 y guarda aristas usadas
        edge &e = edges[i];
        if(mset.root(e.from) == mset.root(e.to)) continue;
        if(e.from != 1) continue;

        deg_1++;
        used[i] = true;
        mset.join(e.from, e.to);
    }

    if(deg_1 > d){
        cout << "NO\n";
        return 0;
    }

    vector<edge> ans;
    mset.reset(n);
    for(int i = 0; i < m; ++i){ /// conecta solo las aristas usadas por 1
        edge &e = edges[i];
        if(mset.root(e.from) == mset.root(e.to)) continue;
        if(!used[i]) continue;

        ans.push_back(e);
        mset.join(e.from, e.to);
    }

    for(edge &e : edges){ /// conecta las aristas faltantes de 1 para llegar a grado d
        if(mset.root(e.from) == mset.root(e.to)) continue;
        if(e.from != 1) continue;
        if(deg_1 == d) break;

        deg_1++;
        ans.push_back(e);
        mset.join(e.from, e.to);
    }

    for(edge &e : edges){ /// conecta el resto del grafo
        if(mset.root(e.from) == mset.root(e.to)) continue;
        if(e.from == 1) continue;

        ans.push_back(e);
        mset.join(e.from, e.to);
    }

    if(deg_1 == d){
        cout << "YES\n";
        for(edge &e : ans) cout << e.from << ' ' << e.to << '\n';
    } else cout << "NO\n";
}
