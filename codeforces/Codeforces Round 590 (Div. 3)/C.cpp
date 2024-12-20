/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int di[4] = {1, -1, 0, 0};
const int dj[4] = {0, 0, 1, -1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> graph[12 * n + 2];
        string s; cin >> s;
        string s2; cin >> s2;
        if(s[0] <= '2')graph[0].push_back(2);
        else graph[0].push_back(4);

        for(int i = 0; i < n; ++i){
            int u = i * 6;
            if(s[i] <= '2'){
                if(i + 1 < n){
                    int v = u + 6;
                    if(s[i + 1] <= '2') graph[u + 2].push_back(v + 2);
                    else graph[u + 2].push_back(v + 4);
                }
            } else {
                if(i + 1 < n){
                    int v = u + 6;
                    if(s[i + 1] <= '2') graph[u + 3].push_back(v + 2);
                    else graph[u + 3].push_back(v + 4);
                }
                if(s2[i] > '2') graph[u + 4].push_back(u + 6 * n + 6);
            }
        }

        for(int i = 0; i < n; ++i){
            int u = (i + n) * 6;
            if(s2[i] <= '2'){
                if(i + 1 < n){
                    int v = u + 6;
                    if(s2[i + 1] <= '2') graph[u + 2].push_back(v + 2);
                    else graph[u + 2].push_back(v + 5);
                }
            } else {
                if(i + 1 < n){
                    int v = u + 6;
                    if(s2[i + 1] <= '2') graph[u + 6].push_back(v + 2);
                    else graph[u + 6].push_back(v + 5);
                }
                if(s[i] > '2') graph[u + 5].push_back(u - 6 * n + 3);
            }
        }

        if(s2[n - 1] <= '2') graph[(2 * n - 1) * 6 + 2].push_back(12 * n + 1);
        else graph[(2 * n - 1) * 6 + 6].push_back(12 * n + 1);

        vector<bool> vis(12 * n + 2);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        while(q.size()){
            int u = q.front(); q.pop();
            for(int v : graph[u]){
                if(vis[v]) continue;
                q.push(v);
                vis[v] = true;
            }
        }

        cout << (vis[12 * n + 1] ? "YES\n" : "NO\n");
    }
}
