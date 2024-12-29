#include <bits/stdc++.h>

using namespace std;

struct persistent_array{
    vector<vector<pair<int, int>>> arr;
    persistent_array(int n){
        arr.resize(n);
    }

    persistent_array(){}

    void resize(int n){
        arr.resize(n);
    }

    /// update solo en la ultima version
    int update(int x, int idx, int t){
        if(arr[idx].empty()){
            arr[idx].push_back({t, x});
            return x;
        }

        if(arr[idx].back().first == t) arr[idx].back().second = x;
        else arr[idx].push_back({t, x});
        return x;
    }

    int at(int idx, int t){
        int l = 0, r = arr[idx].size();
        while(l < r){
            int mid = l + (r - l) / 2;
            if(arr[idx][mid].first <= t) l = mid + 1;
            else r = mid;
        }
        return arr[idx][l - 1].second;
    }
};

struct dsu{
    vector<int> RA;
    persistent_array P;
    dsu(int n){
        RA.resize(n, 1);
        P.resize(n);
        for(int i = 0; i < n; ++i) P.update(i, i, -1);
    }

    int root(int x, const int t){
        return x == P.at(x, t) ? x : root(P.at(x, t), t);
    }

    void join(int x, int y, const int t){
        x = root(x, t - 1);
        y = root(y, t - 1);
        if(x == y) return;
        if(RA[y] < RA[x]) swap(x, y);
        RA[y] += RA[x];
        P.update(y, x, t);
    }
};

struct edge{
    int from, to, w;
    const bool operator>(const edge &b)const{
        return w > b.w;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q; cin >> n >> m >> q;
    vector<edge> edges;
    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        edges.push_back({a, b, c});
    }
    sort(edges.begin(), edges.end(), greater<edge>());

    dsu mset(n);
    for(int i = 0; i < m; ++i){
        edge &e = edges[i];
        mset.join(e.from, e.to, i);
    }

    while(q--){
        int a, b; cin >> a >> b;
        a--, b--;
        int l = 0, r = m;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(mset.root(a, mid) == mset.root(b, mid)) r = mid;
            else l = mid + 1;
        }
        cout << edges[l].w << '\n';
    }
}
