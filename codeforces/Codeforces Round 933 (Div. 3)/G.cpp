/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXC 200000

using namespace std;

struct pos{
    int id, d;
    bool color;

    const bool operator<(const pos &b)const{
        return d > b.d;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        map<int, vector<int>> nodes;
        vector<int> colors[n];
        for(int i = 0; i < m; ++i){
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--, c--;
            colors[a].push_back(c);
            colors[b].push_back(c);
            nodes[c].push_back(a);
            nodes[c].push_back(b);
        }

        int s, e; cin >> s >> e;
        s--, e--;
        if(s == e){
            cout << "0\n";
            continue;
        }

        bool visn[n] = {};
        set<int> visc;
        priority_queue<pos> q;
        q.push({s, 0, false});
        visn[s] = true;
        while(q.size()){
            pos cur = q.top();
            q.pop();

            if(!cur.color && cur.id == e){
                cout << cur.d << '\n';
                break;
            }

            if(cur.color){
                for(int v : nodes[cur.id]){
                    if(visn[v]) continue;
                    visn[v] = true;
                    q.push({v, cur.d, false});
                }
            } else {
                for(int v : colors[cur.id]){
                    if(visc.count(v)) continue;
                    visc.insert(v);
                    q.push({v, cur.d + 1, true});
                }
            }
        }
    }
}
