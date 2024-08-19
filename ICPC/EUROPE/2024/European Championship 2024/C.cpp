/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 200'001

using namespace std;

vector<int> tree[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int grad[n] = {};
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
        grad[a]++;
        grad[b]++;
    }

    int cnt[n];
    fill(cnt, cnt + n, 1);
    set<pair<pair<int, int>, int>> q;
    for(int i = 0; i < n; ++i)
        if(grad[i] == 1) q.insert({{cnt[i], 1}, i});

    while(q.size()){
        int ants, g, u;
        ants = q.begin()->first.first;
        g = q.begin()->first.second;
        u = q.begin()->second;
        q.erase(q.begin());

        for(int v : tree[u]){
            if(cnt[u] > cnt[v]) continue;

            //cout << "Go " << u + 1 << ' ' << v + 1 << ' ' << cnt[v] + cnt[u] << '\n';
            q.erase({{cnt[v], grad[v]}, v});
            cnt[v] += cnt[u];
            cnt[u] = 0;
            grad[v]--;
            q.insert({{cnt[v], grad[v]}, v});
            break;
        }
    }

    int cnt_h = 0;
    for(int i = 0; i < n; ++i) if(cnt[i]) cnt_h++;
    cout << (cnt_h == 1 ? "YES\n" : "NO\n");
}
