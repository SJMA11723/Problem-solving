#include <bits/stdc++.h>

using namespace std;

int n, e, t, res;
vector<int> nodos[101];
int pasos[101];
bitset<101> visitados;

void BFS(){
    queue<int> cola;
    cola.push(n);

    visitados.reset();
    fill(pasos, pasos + n, 1e9);

    pasos[n] = 0;

    while(!cola.empty()){
        int act = cola.front();
        cola.pop();

        for(int it : nodos[act]){
            if(visitados[it]) continue;
            visitados.set(it);
            pasos[it] = pasos[act] + 1;
            cola.push(it);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> e >> t;

    while(e--){
    int a, b;
    cin >> a >> b;
    nodos[a].push_back(b);
    nodos[b].push_back(a);
    }

    BFS();

    for(int i = 1; i < n; ++i){
        if(pasos[i] < t) res++;
    }

    cout << res;

  return 0;
}
