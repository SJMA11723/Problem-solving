/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

set<pair<int, int>> edges;
unordered_set<int> no_visitados;
vector<vector<int>> components;

void bfs(int s){
    if(!no_visitados.count(s)) return;
    no_visitados.erase(s);
    queue<int> q;
    q.push(s);

    vector<int> component;

    while(q.size()){
        int act = q.front();
        q.pop();

        component.push_back(act);
        stack<int> erased;
        for(int v : no_visitados){
            if(edges.count({min(act, v), max(act, v)}))
                continue;
            q.push(v);
            erased.push(v);
        }

        while(erased.size()){
            no_visitados.erase(erased.top());
            erased.pop();
        }
    }
    components.push_back(component);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        if(b < a) swap(a, b);
        edges.insert({a, b});
    }

    for(int i = 1; i <= n; ++i) no_visitados.insert(i);
    for(int i = 1; i <= n; ++i) bfs(i);
    cout << components.size() << '\n';
    for(vector<int> comp : components){
        cout << comp.size() << ' ';
        for(int v : comp) cout << v << ' ';
        cout << '\n';
    }
}
