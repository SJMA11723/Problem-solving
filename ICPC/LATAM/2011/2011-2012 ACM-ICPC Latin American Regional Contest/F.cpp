#include <bits/stdc++.h>
#define set_bit(n, i) ((n) |= (1ll << (i)))
#define is_on(n, i) ((n) & (1ll << (i)))

using namespace std;

const int inf = 1e9;
const int maxn = 1e6;
int s[maxn];
map<int, int64_t> mask[maxn];
map<int, int> to[maxn];

int len[maxn], f_pos[maxn], slink[maxn];
int node, pos;
int sz = 1, n = 0;

int make_node(int _pos, int _len){
    f_pos[sz] = _pos;
    len[sz] = _len;
    return sz++;
}

void go_edge(int id){
    while(pos > len[to[node][s[n - pos]]]){
        node = to[node][s[n - pos]];
        set_bit(mask[node][len[node]], id);
        pos -= len[node];
    }
}

void add_letter(int c, int id){
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
            set_bit(mask[v], pos);
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

void cut_generalized(vector<int> &finish_points){
    for(int i = 0; i < sz; ++i){
        int init = f_pos[i];
        int end = f_pos[i] + len[i] - 1;
        int idx = lower_bound(finish_points.begin(), finish_points.end(), init) - finish_points.begin();
        if(idx != finish_points.size() && finish_points[idx] <= end){
            len[i] = finish_points[idx] - f_pos[i] + 1;
            to[i].clear();
        }
    }
}

void build_generalized(vector<string> &ss){
    for(int i = 0; i < sz; ++i){
        to[i].clear();
    }
    sz = 1;
    node = pos = n = 0;
    len[0] = inf;
    int sep = '$';
    vector<int> finish_points;
    int next = 0;
    for(int i = 0; i < ss.size(); ++i){
        for(int j = 0; j < ss[i].size(); ++j){
            add_letter(ss[i][j], j);
        }
        next += ss[i].size();
        finish_points.push_back(next);
        add_letter(sep++);
        next++;
    }
    correct(next);
    cut_generalized(finish_points);
}

void print_suffix_tree(int from = 0){
	cout << "Edge entering in " << from << " has size " << len[from] << " and starts in " << f_pos[from] << endl;
	cout << "subtr: ";
	for(int i = 0; i < len[from]; ++i) cout << (char)s[f_pos[from] + i]; cout << '\n';
	cout << "Node " << from << " goes to:\n";
	for (auto u : to[from]){
		cout << u.second << " with " << (char)u.first << "\n";
	}
	cout << endl;
	for (auto u : to[from]){
		print_suffix_tree(u.second);
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int f; cin >> f;
    while(f){
        vector<string> words(f);
        for(string &s : words) cin >> s;
        build_generalized(words);

        //print_suffix_tree();

        for(int i = 0; i < words.size(); ++i){
            string &s = words[i];
            int j = 0;
            int u = 0;
            while(j < s.size()){
                set_bit(mask[u][len[u] - 1], i);
                cout << "NODE: " << u << " | j: " << j << '\n';
                cout << "Setting bit " << i << " on pos " << len[u] - 1 << '\n';
                u = to[u][s[j]];
                j += len[u];
            }
            j -= len[u];
            cout << "Final NODE: " << u << " | j: " << j << '\n';
            cout << "Setting bit " << i << " on pos " << (int)s.size() - j - 1 << '\n';
            set_bit(mask[u][(int)s.size() - j - 1], i);
            cout << "ENDSTR\n";
        }

        set<int64_t> ans;
        for(int i = 1; i < sz; ++i){
            if(mask[i].empty()) continue;

            vector<int64_t> masks;
            for(auto &it : mask[i]) masks.push_back(it.second);
            reverse(masks.begin(), masks.end());

            int64_t cur_mask = 0;
            for(int64_t m : masks){
                cur_mask |= m;
                ans.insert(cur_mask);
            }
        }

        cout << ans.size() << '\n';
        for(int m : ans) cout << m << '\n';
        cin >> f;
    }
}
