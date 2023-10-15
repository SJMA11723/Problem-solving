/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;

int n, m[100001];
bool visitado[100001];
vector<int> grafo[100001];
unordered_set<int> hojas;

long long binExp(long long a, long long b){
    long long ans = 1;
    a %= MOD;
    while(b){
        if(b % 2) ans = ans * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return ans;
}

long long bfs(){
    queue< pair<int, long long> > q;

    long long res = 0;
    for(int h : hojas){
        visitado[h] = true;
        q.push({h, 1});
    }

    while(q.size()){
        auto [nodo, pasos] = q.front();
        q.pop();

        res += pasos;

        for(int v : grafo[nodo]){
            if(visitado[v]) continue;
            visitado[v] = true;
            q.push({v, pasos + 1});
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) hojas.insert(i);
    for(int i = 2; i <= n; ++i){
        cin >> m[i];
        hojas.erase(m[i]);
        grafo[i].push_back(m[i]);
        grafo[m[i]].push_back(i);
    }

    long long suma = bfs();
    cout << suma * binExp(n, MOD - 2) % MOD << '\n';
}
