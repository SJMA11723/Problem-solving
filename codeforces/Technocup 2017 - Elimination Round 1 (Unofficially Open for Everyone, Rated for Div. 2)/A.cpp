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
    int64_t a, b; cin >> a >> b;

    map<int64_t, bool> vis;
    queue<pair<int, vector<bool>>> q;
    q.push({a, {}});
    vis[a] = true;
    vector<bool> ops;

    while(q.size()){
        int64_t cur = q.front().first;

        if(cur == b){
            ops = q.front().second;
            break;
        }

        if(!vis[2 * cur] && 2 * cur <= b){
            vis[2 * cur] = true;
            vector<bool> op = q.front().second;
            op.push_back(0);
            q.push({2 * cur, op});
        }

        if(!vis[10 * cur + 1] && 10 * cur + 1 <= b){
            vis[10 * cur + 1] = true;
            vector<bool> op = q.front().second;
            op.push_back(1);
            q.push({10 * cur + 1, op});
        }

        q.pop();
    }

    if(ops.size()){
        cout << "YES\n" << ops.size() + 1 << '\n';
        cout << a << ' ';
        for(bool o : ops){
            if(o) a = 10 * a + 1;
            else a *= 2;
            cout << a << " \n"[a == b];
        }
        cout << '\n';
    } else cout << "NO\n";
}
