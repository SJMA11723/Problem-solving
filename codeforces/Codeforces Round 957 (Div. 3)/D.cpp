/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool bfs(int m, int k, const string &s){
    int n = s.size();
    queue<pair<int, int>> q;
    q.push({0, 0});
    set<int> pending;
    for(int i = 1; i < n; ++i) pending.insert(i);

    while(q.size()){
        int cur, w;
        tie(cur, w) = q.front();
        q.pop();

        if(s[cur] == 'W'){
            if(pending.count(cur + 1) && s[cur + 1] != 'C' && (s[cur + 1] == 'L' || w < k)){
                pending.erase(cur + 1);
                q.push({cur + 1, w + (s[cur + 1] == 'W')});
            }
        } else {
            auto hi = pending.upper_bound(cur + m);
            auto lo = pending.lower_bound(cur + 1);
            vector<int> indices;
            for(auto it = lo; it !=hi; ++it)
                indices.push_back(*it);
            pending.erase(lo, hi);

            reverse(indices.begin(), indices.end());
            for(int i : indices){
                if(s[i] != 'L') continue;
                q.push({i, w});
            }

            for(int i : indices){
                if(s[i] != 'W' || w == k) continue;
                q.push({i, w + 1});
            }
        }
    }
    return !pending.count(n - 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        string s; cin >> s;
        s = "L" + s + "L";
        cout << (bfs(m, k, s) ? "YES\n" : "NO\n");
    }
}
