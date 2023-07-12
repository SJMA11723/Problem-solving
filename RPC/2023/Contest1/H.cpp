/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct nodo{
    int padre;
    vector<int> hijos;
    long long t = 1, r = 0;
}grafo[300001];

vector<int> hojas;

void dfs(int pos, int r){
    if(grafo[pos].hijos.empty()){
        hojas.push_back(pos);
    }

    int p = grafo[pos].padre;
    if(pos) grafo[pos].t = grafo[p].t * (long long)grafo[p].hijos.size();
    if(pos) grafo[pos].r = r * grafo[p].t + grafo[p].r;

    for(int i = 0; i < grafo[pos].hijos.size(); ++i){
        dfs(grafo[pos].hijos[i], i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    int ans[q + 1];

    for(int i = 1; i < n; ++i){
        int x; cin >> x;
        grafo[i].padre = x;
        if(i) grafo[x].hijos.push_back(i);
    }

    /*for(int i = 0; i < n; ++i){
        cout << i << ": ";
        for(int it : grafo[i].hijos)
            cout << it << ' ';
        cout << '\n';
    }*/

    grafo[0].padre = 0;
    dfs(0, 1);

    for(int it : hojas){
        for(long long i = grafo[it].r; i < q; i += grafo[it].t){
            ans[i] = it;
        }
    }

    for(int i = 0; i < q; ++i){
        cout << ans[i] << '\n';
    }
}
