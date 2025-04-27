/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct hline{
    int l, r, idx;
    bool operator<(const hline &b)const{
        return l < b.l;
    }

    bool intersect(const hline b)const{
        return !(r < b.l || b.r < l);
    }
};

struct rectangle{
    int64_t x0, y0, x1, y1;

    int64_t mass(){
        return (x1 - x0) * (y1 - y0);
    }

    int64_t dcenterx(){
        return x0 + x1;
    }
};

struct pos{
    int u;
    int64_t numx = 0, den = 0;
};

pair<int64_t, int64_t> dfs(int u, vector<int> tree[], rectangle arr[], int P[], bool &ok){
    int64_t numx = arr[u].dcenterx() * arr[u].mass(), den = 2 * arr[u].mass();
    for(int v : tree[u]){
        int64_t vn, vd;
        pair<int64_t, int64_t> res = dfs(v, tree, vis, arr, P, ok);
        tie(vn, vd) = res;
        numx += vn;
        den += vd;
        if(!ok) return {0, 0};
    }

    if(P[u] == -1) return {0, 0};

    if(numx < arr[P[u]].x0 * den || den * arr[P[u]].x1 < numx){
        ok = false;
        return {0, 0};
    }

    return {numx, den};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        unordered_map<int, set<hline>> intervals;
        rectangle arr[n];
        for(int i = 0; i < n; ++i){
            int x0, x1, y0, y1;
            cin >> x0 >> y0 >> x1 >> y1;
            arr[i] = {x0, y0, x1, y1};
            intervals[y1].insert({x0, x1, i});
        }

        vector<int> tree[n];
        int P[n];
        memset(P, -1, sizeof(P));

        for(int i = 0; i < n; ++i){
            rectangle rec = arr[i];
            if(rec.y0 == 0) continue;

            auto it = intervals[rec.y0].lower_bound({rec.x0, 0, 0});
            if(it == intervals[rec.y0].end() || it->intersect({rec.x0, rec.x1, 0}) == 0) it--;

            P[i] = it->idx;
            tree[it->idx].push_back(i);
        }

        bool ok = true;
        for(int i = 0; i < n; ++i){
            if(arr[i].y0 > 0) continue;
            dfs(i, tree, vis, arr, P, ok);
        }


        cout << (ok ? "Stable\n" : "Unstable\n");
    }
}
