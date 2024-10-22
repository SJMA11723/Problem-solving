/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    unordered_set<string> vis;

    queue<string> q;
    q.push(s);
    k--;
    int64_t ans = 0;
    while(q.size()){
        string cur = q.front();
        q.pop();

        ans += n - (int)cur.size();

        string pref;
        for(int i = 0; i < cur.size() && vis.size() < k; pref += cur[i++]){
            string ns = pref + cur.substr(i + 1);
            if(vis.count(ns)) continue;
            vis.insert(ns);
            q.push(ns);
        }
    }

    cout << (vis.size() == k ? ans : -1) << '\n';
}
