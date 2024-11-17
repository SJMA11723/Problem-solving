/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int id(int x, int y, int m){
    return x * m + y;
}

pair<int, int> coord(int x, int m){
    return {x / m, x % m};
}

struct dsu{
    vector<int> P, RA;

    dsu(int n){
        RA.resize(n, 1);
        P.resize(n);
        iota(P.begin(), P.end(), 0);
    }

    int root(int x){
        return x == P[x] ? x : P[x] = root(P[x]);
    }

    bool join(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return false;
        if(RA[y] < RA[x]) swap(x, y);
        RA[y] += RA[x];
        P[x] = y;
        return true;
    }
};

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        map<int, vector<int>> vals;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int x; cin >> x;
                vals[x].push_back(id(i, j, m));
            }
        }

        bool ap[n * m] = {};

        dsu mset(n * m);

        int ans = 0, cnt_comp = 0;

        auto it = vals.rbegin();
        while(it != vals.rend()){
            int h = it->first;
            vector<int> &nums = it->second;

            for(int x : nums){
                int i, j;
                tie(i, j) = coord(x, m);
                cnt_comp++;

                bool ok = false;
                for(int k = 0; k < 4; ++k){
                    int ni = i + di[k];
                    int nj = j + dj[k];

                    if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;

                    if(!ap[id(ni, nj, m)]) continue;

                    if(mset.join(x,  id(ni, nj, m))) cnt_comp--;
                }

                ap[x] = true;
            }

            ans = max(ans, cnt_comp);

            it++;
        }

        cout << ans << '\n';
    }
}
