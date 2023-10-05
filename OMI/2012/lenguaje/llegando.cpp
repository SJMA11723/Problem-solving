#include <bits/stdc++.h>

using namespace std;

int n, m, p, d, k, a, b;
int caminoPar[1000005], caminoImpar[1000005];
vector<int> caminos[1000000];

struct pos{
    int posicion, pasos;

    pos(int a, int b){
        posicion = a;
        pasos = b;
    }
};

void llegandoBFS(){
    queue<pos> cola;
    pos primero(1, 0);
    cola.push(primero);

    while(!cola.empty()){
        pos act = cola.front();
        cola.pop();

        for(int it: caminos[act.posicion]){
            if( (act.pasos%2 && !caminoPar[it]) ||
            (act.pasos%2==0 && !caminoImpar[it]) ) {

                if(act.pasos%2) caminoPar[it] = act.pasos+1;
                else caminoImpar[it] = act.pasos+1;

                pos nuevo(it, act.pasos+1);
                cola.push(nuevo);
            }
        }
    }
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        caminos[a].push_back(b);
        caminos[b].push_back(a);
    }

    cin >> p;
    llegandoBFS();
    caminoPar[1] = -2;

    for(int i = 0; i < p; ++i){
        cin >> d >> k;
        if( (k%2 && caminoImpar[d] && caminoImpar[d] <= k )
           || (k%2 == 0 && caminoPar[d] && caminoPar[d] <= k)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}
}
