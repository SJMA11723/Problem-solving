#include<bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int maxn = 1e6;
int s[maxn];
map<int, int> to[maxn];
int len[maxn], f_pos[maxn], slink[maxn];
int node, pos;
int sz = 1, n = 0;

int make_node(int _pos, int _len){
    f_pos[sz] = _pos;
    len[sz] = _len;
    return sz++;
}

void go_edge(){
    while(pos > len[to[node][s[n - pos]]]){
        node = to[node][s[n - pos]];
        pos -= len[node];
    }
}

void add_letter(int c){
    s[n++] = c;
    pos++;
    int last = 0;
    while(pos > 0){
        go_edge();
        int edge = s[n - pos];
        int &v = to[node][edge];
        int t = s[f_pos[v] + pos - 1];
        if(v == 0){
            v = make_node(n - pos, inf);
            slink[last] = node;
            last = 0;
        } else if(t == c){
            slink[last] = node;
            return;
        } else {
            int u = make_node(f_pos[v], pos - 1);
            to[u][c] = make_node(n - 1, inf);
            to[u][t] = v;
            f_pos[v] += pos - 1;
            len[v] -= pos - 1;
            v = u;
            slink[last] = u;
            last = u;
        }
        if(node == 0) pos--;
        else node = slink[node];
    }
}

void correct(int s_size){
    len[0] = 0;
    for(int i = 1; i < sz; ++i){
        if(f_pos[i] + len[i] - 1 >= s_size){
            len[i] = (s_size - f_pos[i]);
        }
    }
}

void build(string &p){
    for(int i = 0; i < sz; ++i){
        to[i].clear();
    }

    sz = 1;
    node = pos = n = 0;
    len[0] = inf;
    for(int i = 0; i < p.size(); ++i){
        add_letter(p[i]);
    }
    correct(p.size());
}

void print(int from, int p = - 1){
    cout << "Parent: " << p << '\n';
    cout << "Edge entering in " << from << " has size " << len[from];
    cout << " and starts in " << f_pos[from] << '\n';
    cout << "Node " << from << " goes to:\n";
    for(auto u : to[from]){
        cout << u.second << " with " << (char)u.first << ' ' << u.first << "\n";
    }
    cout << '\n';
    for(auto u : to[from]){
        print(u.second, from);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string t; cin >> t;
    build(t);

    int q; cin >> q;
    while(q--){
        string p; cin >> p;
        int n = p.size();
        int ans = 1, idx = 0;
        bool ok = true;
        int node = 0;

        while(idx < n){
            if(!to[node].count(p[idx])){
                if(!node){
                    ok = false;
                    break;
                }
                ans++;
                node = 0;
                continue;
            } else node = to[node][p[idx]];

            bool break_edge = false;
            int init = f_pos[node];
            for(int i = 0; i < len[node] && idx < n; ++i){
                if(t[init + i] == p[idx]) idx++;
                else {
                    node = 0;
                    break_edge = true;
                    break;
                }
            }

            if(break_edge){
                node = 0;
                ans++;
                continue;
            }

            if(idx < n && !to[node].count(p[idx])){
                ans++;
                node = 0;
            }
        }

        if(ok) cout << ans << '\n';
        else cout << "-1\n";
    }
}

/***
MONTEVIDEO
Parent: -1
Edge entering in 0 has size 0 and starts in 0
Node 0 goes to:
8 with D 68
9 with E 69
7 with I 73
1 with M 77
3 with N 78
2 with O 79
4 with T 84
6 with V 86

Parent: 0
Edge entering in 8 has size 3 and starts in 7
Node 8 goes to:

Parent: 0
Edge entering in 9 has size 1 and starts in 4
Node 9 goes to:
10 with O 79
5 with V 86

Parent: 9
Edge entering in 10 has size 1 and starts in 9
Node 10 goes to:

Parent: 9
Edge entering in 5 has size 5 and starts in 5
Node 5 goes to:

Parent: 0
Edge entering in 0
7 has size 4 and starts in 6
Node 7 goes to:

Parent: 0
Edge entering in 1 has size 10 and starts in 0
Node 1 goes to:

Parent: 0
Edge entering in 3 has size 8 and starts in 2
Node 3 goes to:

Parent: 0
Edge entering in 2 has size 9 and starts in 1
Node 2 goes to:

Parent: 0
Edge entering in 4 has size 7 and starts in 3
Node 4 goes to:

Parent: 0
Edge entering in 6 has size 5 and starts in 5
Node 6 goes to:
*/


