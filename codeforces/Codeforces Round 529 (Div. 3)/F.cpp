/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to;
    int64_t w;

    bool operator<(const edge &b){
        return w < b.w;
    }
};

struct dsu{
    vector<int> RA, P;
    dsu(int n){
        RA.resize(n, 1);
        P.resize(n);
        iota(P.begin(), P.end(), 0);
    }

    int root(int x){
        return (x == P[x] ? x : P[x] = root(P[x]));
    }

    bool join(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return false;
        if(RA[x] >= RA[y]) swap(x, y);
        RA[y] += RA[x];
        P[x] = y;
        return true;
    }
};

int64_t kruskal(int n, vector<edge> &edges){
    sort(edges.begin(), edges.end());
    dsu mset(n);
    int64_t res = 0;
    for(edge &e : edges){
        if(mset.join(e.from, e.to)) res += e.w;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    pair<int64_t, int> arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr + n);

    vector<edge> edges;

    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        int64_t w; cin >> w;
        a--, b--;
        edges.push_back({a, b, w});
    }

    for(int i = 1; i < n; ++i) edges.push_back({arr[0].second, arr[i].second, arr[0].first + arr[i].first});

    cout << kruskal(n, edges) << '\n';
}
