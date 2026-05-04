/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 998244353;

struct SplayTree {
  struct Node {
    int ch[2] = {0, 0}, p = 0;
    long long self = 0, path = 0;        // Path aggregates
    long long sz = 0, sub = 0, vir = 0;          // Subtree aggregates
    bool flip = 0;                       // Lazy tags
  };
  vector<Node> T;
 
  SplayTree(int n) : T(n + 1) {}
  
  void push(int x) {
    if (!x || !T[x].flip) return;
    int l = T[x].ch[0], r = T[x].ch[1];
 
    T[l].flip ^= 1, T[r].flip ^= 1;
    swap(T[x].ch[0], T[x].ch[1]);
    T[x].flip = 0;
  }
  
  void pull(int x) {
    int l = T[x].ch[0], r = T[x].ch[1]; push(l); push(r); 
 
    T[x].path = T[l].path + T[x].self + T[r].path;
    T[x].sub = T[x].vir + T[l].sub + T[r].sub + T[x].sz;
  }
  
  void set(int x, int d, int y) {
    T[x].ch[d] = y; T[y].p = x; pull(x); 
  }
 
  void splay(int x) { 
    auto dir = [&](int x) {
      int p = T[x].p; if (!p) return -1;
      return T[p].ch[0] == x ? 0 : T[p].ch[1] == x ? 1 : -1;
    };
    auto rotate = [&](int x) {
      int y = T[x].p, z = T[y].p, dx = dir(x), dy = dir(y);
      set(y, dx, T[x].ch[!dx]); 
      set(x, !dx, y);
      if (~dy) set(z, dy, x); 
      T[x].p = z;
    };
    for (push(x); ~dir(x); ) {
      int y = T[x].p, z = T[y].p;
      push(z); push(y); push(x);
      int dx = dir(x), dy = dir(y);
      if (~dy) rotate(dx != dy ? x : y);
      rotate(x);
    }
  }
};
 
struct LinkCut : SplayTree {
  LinkCut(int n) : SplayTree(n) {}
 
  int access(int x) {
    int u = x, v = 0;
    for (; u; v = u, u = T[u].p) {
      splay(u); 
      int& ov = T[u].ch[1];
      T[u].vir += T[ov].sub;
      T[u].vir -= T[v].sub;
      ov = v; pull(u);
    }
    return splay(x), v;
  }
 
  void reroot(int x) { 
    access(x); T[x].flip ^= 1; push(x); 
  }
  
  void Link(int u, int v) { 
    reroot(u); access(v); 
    T[v].vir += T[u].sub;
    T[u].p = v; pull(v);
  }
  
  void Cut(int u, int v) {
    reroot(u); access(v);
    T[v].ch[0] = T[u].p = 0; pull(v);
  }
  
  // Rooted tree LCA. Returns 0 if u and v arent connected.
  int LCA(int u, int v) { 
    if (u == v) return u;
    access(u); int ret = access(v); 
    return T[u].p ? ret : 0;
  }
  
  // Query subtree of u where v is outside the subtree.
  long long Subtree(int u, int v) {
    reroot(v); access(u); return T[u].vir + T[u].self;
  }
  
  // Query path [u..v]
  long long Path(int u, int v) {
    reroot(u); access(v); return T[v].path;
  }
  
  // Update vertex u with value v and size x
  void Update(int u, long long v, long long x) {
    access(u); T[u].self = v; T[u].sz = x; pull(u);
  }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;

        vi pos[n + 1];
        for(int i = 1; i <= n; ++i){
            int ai; cin >> ai;
            pos[ai].pb(i);
        }

        int ans = 0, partial_ans = 0;
        int N = n + 1;
        LinkCut tree(N + n + 1);
        for(int i = 1; i <= n; ++i){
            tree.Update(i, 0, 1);
            tree.Link(i, i + 1);

            tree.Update(N + i, i, 0);
        }
        tree.reroot(N);


        for(int x = n; 0 < x; --x){
            ans += partial_ans;
            if(ans >= MOD) ans -= MOD;
            //cout << "partial ans = " << partial_ans << '\n';

            for(int i : pos[x]){
                int p = min(i + k, n + 1);
                int w = n - i + 1;

                tree.access(i);
                ll a = tree.T[i].path;

                tree.Cut(i, i + 1);
                tree.Link(N + w, p);
                tree.Link(i, N + w);
                
                tree.reroot(N);
                tree.access(i);

                ll b = tree.T[i].path;

                partial_ans += 1ll * (tree.T[i].vir + tree.T[i].sz) * ((b - a) % MOD + MOD) % MOD;
                if(partial_ans >= MOD) partial_ans -= MOD;
            }
        } //cout << '\n';
        cout << ans << '\n';
    }
}