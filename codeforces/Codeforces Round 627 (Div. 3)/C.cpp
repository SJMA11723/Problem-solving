/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool check(string &s, int d){
    set<int> pending;
    for(int i = 1; i <= s.size(); ++i) pending.insert(i);

    queue<int> q;
    q.push(0);
    while(q.size()){
        int u = q.front();
        q.pop();

        if(u == s.size()) return true;

        if(s[u] == 'R'){
            auto it = pending.upper_bound(u);
            while(it != pending.end() && *it <= u + d){
                q.push(*it);
                it = pending.erase(it);
            }
        } else {
            auto it = pending.lower_bound(u);
            while(it != pending.begin()){
                it--;
                if(u - d <= *it) q.push(*it);
                else {
                    it++;
                    break;
                }
            }

            while(it != pending.end() && u - d <= *it && *it <= u) it = pending.erase(it);
        }
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        s = "R" + s;
        int l = 0, r = s.size() + 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(check(s, mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << '\n';
    }
}
