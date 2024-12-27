/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void dfs(int u, vector<int> tree[], int d, int &max_d, int &u_d, int p = -1){
    if(d > max_d){
        u_d = u;
        max_d = d;
    }
    for(int v : tree[u])
        if(v != p) dfs(v, tree, d + 1, max_d, u_d, u);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<int> tree[n];
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int l, max_d = -1;
    dfs(0, tree, 0, max_d, l);

    int r; max_d = -1;
    dfs(l, tree, 0, max_d, r);

    int d[n] = {};
    int p[n];
    queue<int> q;
    q.push(l);
    d[l] = 1;
    p[l] = l;
    while(q.size()){
        int u = q.front(); q.pop();
        for(int v : tree[u]){
            if(d[v]) continue;
            d[v] = 1;
            p[v] = u;
            q.push(v);
        }
    }

    int a = l, b = r, c;

    memset(d, 0, sizeof(d));
    while(p[r] != r){
        q.push(r);
        d[r] = 1;
        r = p[r];
    }
    q.push(l);
    d[l] = 1;
    while(q.size()){
        int u = q.front(); q.pop();
        for(int v : tree[u]){
            if(d[v]) continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }

    c = -1;
    for(int i = 0; i < n; ++i){
        if(i == a || i == b) continue;
        if(c == -1 || d[c] < d[i]) c = i;
    }

    cout << max_d + d[c] - 1 << '\n' << a + 1 << ' ' << b + 1 << ' ' << c + 1 << '\n';
}
