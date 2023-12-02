/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
set<pair<int, int> > edges;

int bfs(){
    priority_queue<pair<int, int> > q;
    q.push({0, 1});
    vector<char> visitado(n + 1);
    set<int> no_visitado;
    for(int i = 2; i <= n; ++i) no_visitado.insert(i);
    int ans = 0;

    while(q.size()){
        auto [c, from] = q.top();
        c = -c;
        q.pop();

        if(visitado[from]) continue;
        visitado[from] = true;
        if(no_visitado.count(from))
            no_visitado.erase(from);

        ans += c;

        bool ok = false;
        stack<int> erased;
        for(int to : no_visitado){
            if(edges.count({from, to})) continue;
            ok = true;
            q.push({0, to});
            erased.push(to);
        }
        while(erased.size()){
            no_visitado.erase(erased.top());
            erased.pop();
        }

        if(!ok && no_visitado.size())
            q.push({-1, *no_visitado.begin()});
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        edges.insert({a, b});
        edges.insert({b, a});
    }
    cout << bfs() << '\n';
}
