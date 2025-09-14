#include <bits/stdc++.h>
#define MAXX 1000000

using namespace std;

struct edge{
    int from, to;
    int w;
};

struct segment{
    int x1, y1, x2, y2;
};

pair<int, int> dfs(int u, int x, vector<edge> graph[], pair<int, int> dp[], segment arr[]){
    if(arr[u].y1 == arr[u].y2) return {x, arr[u].y1};

    int out = arr[u].y1 < arr[u].y2 ? arr[u].x2 : arr[u].x1;
    if(graph[u].empty()) return {out, INT_MAX};

    if(dp[u] != make_pair(-1, -1)) return dp[u];

    return dp[u] = dfs(graph[u][0].to, out, graph, dp, arr);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;
    vector<pair<int, int>> cub[MAXX + 1];
    bool horizontal[n] = {};
    int y[n];
    segment arr[n];
    for(int i = 0; i < n; ++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(c < a){
            swap(a, c);
            swap(b, d);
        }
        arr[i] = {a, b, c, d};
        if(b == d){
            horizontal[i] = true;
            y[i] = b;
        }
        cub[a].push_back({b, i});
        cub[c].push_back({d, -i - 1});
    }

    int first[MAXX + 1];
    fill(first, first + MAXX + 1, -1);
    set<pair<int, int>> mset;
    vector<edge> graph[n];
    for(int x = 0; x <= 10; ++x){
        for(auto [y, i] : cub[x]){
            if(i < 0) continue;
            mset.insert({y, i});
            if(horizontal[i]) continue;

            auto it = mset.upper_bound({y, INT_MAX});
            if(it == mset.end()) continue;

            int up = it->second;
            if(up < 0) up = -up - 1;

            if(arr[i].y1 > arr[i].y2){
                graph[i].push_back({i, up, arr[i].x1});
            }
        }

        if(mset.size()) first[x] = mset.begin()->second < 0 ? -(mset.begin()->second) + 1 : mset.begin()->second;


        //cout << "x = " << x << '\n';
        //for(auto [y, i] : mset) cout << y << ' ' << i << '\n';

        //if(x == 3){
        //    for(auto [y, i] : cub[x]) cout << y << ' ' << i << '\n';
        //}

        for(auto [y, i] : cub[x]){
            if(i >= 0) continue;
            i = -i - 1;

            auto it = mset.upper_bound({arr[i].y1, INT_MAX});
            if(it == mset.end() || horizontal[i]){
                mset.erase({arr[i].y1, i});
                continue;
            }

            int up = it->second;
            if(up < 0) up = -up - 1;

            if(arr[i].y1 < arr[i].y2){
                graph[i].push_back({i, up, arr[i].x2});
            }

            mset.erase({arr[i].y1, i});
        }
    }

    //for(int i = 0; i < n; ++i){
    //    cout << i << ": ";
    //    for(edge &e : graph[i]) cout << e.to << ' ';
    //    cout << '\n';
    //}

    pair<int, int> dp[n];
    fill(dp, dp + n, make_pair(-1, -1));

    while(q--){
        int x; cin >> x;
        if(first[x] == -1){
            cout << x << '\n';
            continue;
        }

        //cout << "first: " << first[x] << '\n';

        if(horizontal[first[x]]){
            cout << x << ' ' << y[first[x]] << '\n';
            continue;
        }

        pair<int, int> ans = dfs(first[x], x, graph, dp, arr);
        cout << ans.first;
        if(ans.second != INT_MAX) cout << ' ' << ans.second;
        cout << '\n';
    }
}
