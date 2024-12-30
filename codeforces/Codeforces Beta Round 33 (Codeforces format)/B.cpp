/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to;
    int w;
};

vector<vector<int>> floyd_warshall(int n, vector<edge> &edges){
    vector<vector<int>> d(n, vector<int>(n, INT_MAX));
    for(int i = 0; i < n; ++i) d[i][i] = 0;
    for(edge &e : edges)
        d[e.from][e.to] = min(d[e.from][e.to], e.w);

    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(d[i][k] == INT_MAX) continue;
                if(d[k][j] == INT_MAX) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    return d;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t; cin >> s >> t;
    int n; cin >> n;
    vector<edge> edges;
    for(int i = 0; i < n; ++i){
        char a, b; cin >> a >> b;
        int w; cin >> w;
        edges.push_back({a - 'a', b - 'a', w});
    }

    if(s.size() != t.size()){
        cout << "-1\n";
        return 0;
    }

    vector<vector<int>> d = floyd_warshall(26, edges);

    string ans;
    int cost = 0;
    for(int i = 0; i < s.size(); ++i){
        int a = s[i] - 'a';
        int b = t[i] - 'a';
        int mini = INT_MAX;
        char c;
        for(int j = 0; j < 26; ++j){
            if(d[a][j] == INT_MAX || d[b][j] == INT_MAX) continue;
            if(d[a][j] + d[b][j] < mini){
                mini = d[a][j] + d[b][j];
                c = j + 'a';
            }
        }
        if(mini == INT_MAX){
            cout << "-1\n";
            return 0;
        }
        ans += c;
        cost += mini;
    }
    cout << cost << '\n' << ans << '\n';
}
