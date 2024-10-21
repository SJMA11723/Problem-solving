/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct aho_corasick{
    const static int K = 2;
    char index = '0';

    struct vertex{
        int next[K];
        bool terminal = false;
        int p = -1;
        char p_edge;
        int link = -1;
        int go[K];
        vertex(int p = -1, char c = '$') : p(p), p_edge(c){
            fill(next, next + K, -1);
            fill(go, go + K, -1);
        }
    };

    vector<vertex> aho;

    aho_corasick(){
        aho.resize(1);
    }

    void add_string(const string &s){
        int u = 0;
        for(char c : s){
            int e = c - index;
            if(aho[u].next[e] == -1){
                aho[u].next[e] = aho.size();
                aho.emplace_back(u, c);
            }
            u = aho[u].next[e];
        }
        aho[u].terminal = true;
    }

    int go(int u, char c){
        int e = c - index;
        if(aho[u].go[e] == -1){
            if(aho[u].next[e] != -1) aho[u].go[e] = aho[u].next[e];
            else aho[u].go[e] = !u ? 0 : go(get_link(u), c);
        }
        return aho[u].go[e];
    }

    int get_link(int u){
        if(aho[u].link == -1){
            if(!u || !aho[u].p) aho[u].link = 0;
            else aho[u].link = go(get_link(aho[u].p), aho[u].p_edge);
        }
        return aho[u].link;
    }

    int next_node(int u, char c){
        return aho[u].next[c - index];
    }

    int size(){
        return aho.size();
    }

    bool terminal(int u){
        return aho[u].terminal;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    while(n && m){
        aho_corasick aho;
        for(int i = 0; i < n; ++i){
            string s; cin >> s;
            s.pop_back();
            aho.add_string(s);
        }

        uint64_t pow2[m + 1];
        pow2[0] = 1;
        for(int i = 1; i <= m; ++i) pow2[i] = pow2[i - 1] * 2;

        int k; cin >> k;
        while(k--){
            string s; cin >> s;

            s.pop_back();
            int u = 0;
            int depth = 0;
            for(char c : s){
                u = aho.next_node(u, c);
                depth++;
            }

            uint64_t ans = pow2[m - depth];
            queue<pair<int, int>> q;
            q.push({u, depth});
            while(q.size()){
                int cur, d;
                tie(cur, d) = q.front(); q.pop();

                if(cur == -1) continue;

                if(aho.terminal(cur) && cur != u){
                    ans -= pow2[m - d];
                    continue;
                }

                q.push({aho.next_node(cur, '0'), d + 1});
                q.push({aho.next_node(cur, '1'), d + 1});
            }

            cout << ans << '\n';
        }

        cout << '\n';
        cin >> n >> m;
    }
}
