#include <bits/stdc++.h>
#define MAXN 1000001

using namespace std;

vector<int> grafo[MAXN];
bool visitado[MAXN];
int ans[MAXN];
int grupos[MAXN];
int cub[MAXN];

void dfs(int nodo, int &g){
    ans[nodo] = g;
    for(int it : grafo[nodo]){
        if(visitado[it]) continue;
        visitado[it] = true;
        cub[ grupos[it] ]++;
        if(cub[ grupos[it] ] == 1) g++;
        dfs(it, g);
        cub[ grupos[it] ]--;
        if(cub[ grupos[it] ] == 0) g--;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int raiz;
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        int s; cin >> s;
        grafo[s].push_back(i);
        if(s == 0) raiz = i;
    }

    for(int i = 1; i <= n; ++i){
        cin >> grupos[i];
    }

    visitado[raiz] = true;
    int g = 1;
    cub[ grupos[raiz] ]++;
    dfs(raiz, g);
    for(int i = 1; i <= n; ++i){
        cout << ans[i];
        if(i == n) cout << '\n';
        else cout << ' ';
    }
    return 0;
}
