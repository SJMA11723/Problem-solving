/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 100001

using namespace std;

int n, m, k;
vector<int> grafo[MAXN];
int idx[MAXN], depth[MAXN];
int idx_ini;
bool encontrado;
vector<char> visitado(MAXN);
vector<int> alter[2];

void dfs(int nodo, vector<int> &vertices, int d = 1, int P = 0, bool alt = 0){
    idx[nodo] = vertices.size();
    vertices.push_back(nodo);
    visitado[nodo] = true;
    depth[nodo] = d;
    alter[alt].push_back(nodo);

    for(int v : grafo[nodo]){
        if(!visitado[v] || v == P || encontrado || depth[v] >= d) continue;

        if(d - depth[v] + 1 <= k) idx_ini = idx[v];
        else idx_ini = -1;
        encontrado = true;
    }

    if(encontrado) return;

    for(int v : grafo[nodo]){
        if(visitado[v] || v == P || encontrado) continue;
        dfs(v, vertices, d + 1, nodo, !alt);
    }

    if(!encontrado) vertices.pop_back();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    while(m--){
        int a, b;
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    fill(depth, depth + MAXN, INT_MAX);
    vector<int> vertices;
    dfs(1, vertices);
    if(vertices.empty()){
        idx_ini = -1;
        int alt = (alter[0].size() < alter[1].size()) ? 1 : 0;
        for(int i = 0; i < (k + 1) / 2; ++i)
            vertices.push_back(alter[alt][i]);
    } else if(idx_ini == -1){
        vector<int> par, impar;
        for(int i = 0; i < vertices.size(); ++i)
            if(i % 2) impar.push_back(vertices[i]);
            else par.push_back(vertices[i]);
        vertices = (par.size() >= (k + 1) / 2) ? par : impar;
    }

    if(idx_ini == -1){
        cout << "1\n";
        for(int i = 0; i < (k + 1) / 2; ++i) cout << vertices[i] << ' ';
        cout << '\n';
    } else {
        cout << "2\n" << (int)vertices.size() - idx_ini << '\n';
        for(int i = idx_ini; i < vertices.size(); ++i) cout << vertices[i] << ' ';
        cout << '\n';
    }
}
