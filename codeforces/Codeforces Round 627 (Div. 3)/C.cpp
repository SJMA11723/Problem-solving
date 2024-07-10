/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool bfs(int from, string &s, const int d){
    int n = s.size();

    queue<int> q;
    q.push(from);
    set<int> pending;
    for(int i = 0; i < n; ++i) pending.insert(i);
    pending.erase(from);

    while(q.size()){
        int cur = q.front();
        q.pop();

        if(s[cur] == 'L'){
            auto lo = pending.lower_bound(max(0, cur - d));
            auto hi = pending.lower_bound(cur);
            for(auto it = lo; it != hi; ++it) q.push(*it);
            pending.erase(lo, hi);
        }
        else {
            auto lo = pending.lower_bound(cur + 1);
            auto hi = pending.lower_bound(min(n, cur + d + 1));
            for(auto it = lo; it != hi; ++it) q.push(*it);
            pending.erase(lo, hi);
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
        string s; cin >> s;
        s = "R" + s + "L";

        int l = 0, r = s.size();
        while(l < r){
            int mid = l + (r - l) / 2;
            if(bfs(0, s, mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << '\n';
    }
}
