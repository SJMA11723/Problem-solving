#include <bits/stdc++.h>

using namespace std;

const int INF = 1e8;

struct edge{
    int from, to, w;
};

void floyd_warshall(int n, vector<edge> &edges, vector<vector<vector<int>>> &d, pair<int, int> nodes[]){
    for(int i = 0; i < n; ++i) d[0][i][i] = 0;
    for(edge &e : edges){
        d[0][e.from][e.to] = min(d[0][e.from][e.to], e.w);
        d[0][e.to][e.from] = min(d[0][e.to][e.from], e.w);
    }

    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            int u = nodes[i].second;
            for(int j = 0; j < n; ++j){
                int v = nodes[j].second;
                d[k + 1][u][v] = d[k][u][v];
            }
        }

        int w = nodes[k].second;
        for(int i = 0; i < n; ++i){
            int u = nodes[i].second;
            for(int j = 0; j < n; ++j){
                int v = nodes[j].second;
                //cout << "try: " << k + 1 << ' ' << u + 1 << ' ' << w + 1 << ' ' << v + 1 << ' ' << d[k + 1][u][v] << '\n';
                if(d[k][u][w] + d[k][w][v] < d[k + 1][u][v]){
                    d[k + 1][u][v] = d[k][u][w] + d[k][w][v];
                    //cout << "update: " << k + 1 << ' ' << u + 1 << ' ' << w + 1 << ' ' << v + 1 << ' ' << d[k + 1][u][v] << '\n';
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, r; cin >> n >> r;
    pair<int, int> arr[n];
    int temp[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i].first;
        arr[i].second = i;
        temp[i] = arr[i].first;
    }
    sort(temp, temp + n);
    int len_temp = unique(temp, temp + n) - temp;

    vector<edge> edges;
    for(int i = 0; i < r; ++i){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        edges.push_back({a, b, c});
    }

    vector<vector<vector<int>>> mini, maxi;
    mini.resize(n + 1, vector<vector<int>>(n, vector<int>(n, INF)));
    maxi = mini;

    sort(arr, arr + n);
    floyd_warshall(n,  edges, mini, arr);

    reverse(arr, arr + n);
    floyd_warshall(n, edges, maxi, arr);

    reverse(arr, arr + n);
    int q; cin >> q;
    while(q--){
        int a, b, k, t;
        cin >> a >> b >> k >> t;
        k = min(k, len_temp);
        a--, b--;
        if(t == 1){
            int l = 0, r = n;
            while(l < r){
                int mid = l + (r - l) / 2;
                if(arr[mid].first < temp[len_temp - k]) l = mid + 1;
                else r = mid;
            }

            if(maxi[n - l][a][b] == INF) cout << "-1\n";
            else cout << maxi[n - l][a][b] << '\n';
        } else {
            int l = 0, r = n;
            while(l < r){
                int mid = l + (r - l) / 2;
                if(arr[mid].first <= temp[k - 1]) l = mid + 1;
                else r = mid;
            }
            if(mini[l][a][b] == INF) cout << "-1\n";
            else cout << mini[l][a][b] << '\n';
        }
    }
}
