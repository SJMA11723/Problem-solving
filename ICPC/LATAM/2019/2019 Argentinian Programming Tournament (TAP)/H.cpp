#include <bits/stdc++.h>

using namespace std;

struct aho_corasick{
    const static int K = 29;
    const char index = 'a';
    struct vertex{
        int next[K];
        int terminal = 0;
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
    aho_corasick(){aho.resize(1);}

    void add_string(const string &s){
        int u = 0;
        for(char c : s){
            int e = c - index;
            if(c == ',') e = 'z' - 'a' + 1;
            else if(c == '.') e = 'z' - 'a' + 2;
            else if(c == '_') e = 'z' - 'a' + 3;

            if(aho[u].next[e] == -1){
                aho[u].next[e] = aho.size();
                aho.emplace_back(u, c);
            }
            u = aho[u].next[e];
        }
        aho[u].terminal++;
    }

    int get_link(int u){
        if(aho[u].link == -1){
            if(!u || !aho[u].p) aho[u].link = 0;
            else aho[u].link = go(get_link(aho[u].p), aho[u].p_edge);
        }
        return aho[u].link;
    }

    int go(int u, char c){
        int e = c - index;
        if(c == ',') e = 'z' - 'a' + 1;
        else if(c == '.') e = 'z' - 'a' + 2;
        else if(c == '_') e = 'z' - 'a' + 3;

        if(aho[u].go[e] == -1){
            if(aho[u].next[e] != -1) aho[u].go[e] = aho[u].next[e];
            else aho[u].go[e] = !u ? 0 : go(get_link(u), c);
        }
        return aho[u].go[e];
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    string t; cin >> t;
    int r, m; cin >> r >> m;
    aho_corasick aho;

    for(int i = 0; i < r; ++i){
        string p; cin >> p;
        aho.add_string(p);
        string tmp = p;
        for(int j = 0; j < m; ++j){
            char original = p[j];
            for(char c = 'a'; c <= 'z'; ++c){
                p[j] = c;
                if(c != original) aho.add_string(p);
            }
            p[j] = ',';
            if(p[j] != original) aho.add_string(p);
            p[j] = '.';
            if(p[j] != original) aho.add_string(p);
            p[j] = '_';
            if(p[j] != original) aho.add_string(p);

            p[j] = original;
        }
    }

    int ans = 0;
    int u = 0;
    for(char c : t){
        //cout << u << ' ' << c << ' ';
        u = aho.go(u, c);
        ans += aho.aho[u].terminal;
        //cout << u << ' ' << aho.aho[u].terminal << ' ' << ans << '\n';
    }

    cout << ans << '\n';
}
