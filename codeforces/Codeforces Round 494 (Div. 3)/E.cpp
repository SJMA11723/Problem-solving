/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, d, k; cin >> n >> d >> k;

    if(n <= d || (k == 1 && d > 1)){
        cout << "NO\n";
        return 0;
    }

    vector<pair<int, int>> edges;
    queue<int> q;
    int deg[n] = {}, dist_diam[n] = {};
    for(int i = 0; i < min(d, n); ++i){ /// crea diametro
        deg[i]++;
        deg[i + 1]++;
        dist_diam[i] = max(i, d - i);
        edges.push_back({i, i + 1});
        q.push(i);
    }
    q.pop();

    int next_node = d + 1;
    while(q.size()){
        int cur = q.front();
        q.pop();
        for(int i = 0; next_node < n && deg[cur] < k && deg[next_node] < k && dist_diam[cur] < d; ++i){ /// agrega mientras no supere el grado o diametro
            deg[cur]++;
            deg[next_node]++;

            dist_diam[next_node] = dist_diam[cur] + 1;
            edges.push_back({cur, next_node});

            q.push(next_node++);
        }
    }

    if(next_node == n){ /// se utilizaron todos los nodos
        cout << "YES\n";
        for(auto [u, v] : edges) cout << u + 1 << ' ' << v + 1 << '\n';
    } else cout << "NO\n";
}
