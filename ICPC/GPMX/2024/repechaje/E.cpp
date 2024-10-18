#include<bits/stdc++.h>
#define MAXN 100000

using namespace std;

const int MOD = 1e9 + 7;

struct edge{
    int from, to;
    int  w;
    const bool operator<(const edge &b)const{
        return w > b.w;
    }
};

struct pos{
    int from;
    int  c;
    const bool operator<(const pos &b)const{
        return c > b.c;
    }
};

void dijkstra(int a, int n, vector<edge> graph[], int d[]){
    bool vis[MAXN] = {};
    fill(d, d + n, INT_MAX);

    priority_queue<pos> pq;
    pq.push({a, 0});
    d[a] = 0;
    while(pq.size()){
        pos cur = pq.top();
        pq.pop();
        if(vis[cur.from]) continue;
        vis[cur.from] = true;
        for(edge &e : graph[cur.from]){
            if(d[e.to] <= d[cur.from] + e.w) continue;
            d[e.to] = d[cur.from] + e.w;
            pq.push({e.to, d[e.to]});
        }
    }
}

int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b % 2) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int fact[MAXN + 1], inv_fact[MAXN + 1];

int combi(int n, int k){
    if(k > n) return 0;
    return 1ll * fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    for(int i = 1; i <= MAXN; ++i) fact[i] = 1ll * i * fact[i - 1] % MOD;
    inv_fact[MAXN] = bin_exp(fact[MAXN], MOD - 2);
    //cout << "INVERSO " << inv_fact[MAXN] << ' ' << fact[MAXN] << '\n';
    for(int i = MAXN; 0 < i; --i) inv_fact[i - 1] = 1ll * i * inv_fact[i] % MOD;

    int n, m, k; cin >> n >> m >> k;
    vector<edge> graph[MAXN];
    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({a, b, c});
        graph[b].push_back({b, a, c});
    }

    int d[MAXN] = {};
    dijkstra(0, n, graph, d);

    //cout << "D: ";
    //for(int i = 0; i < n; ++i) cout << d[i] << ' '; cout << '\n';

    map<int, int> cnt;
    for(int x : d) cnt[x]++;
    vector<pair<int, int> > freq;
    for(auto it : cnt) freq.push_back(make_pair(it.first, it.second));
    reverse(freq.begin(), freq.end());

    int sum = 0;
    int ans = 0;
    for(pair<int, int> &p : freq){
        int v, f; tie(v, f) = p;
        for(int j = 1; j <= min(k, f); ++j){
            ans += 1ll * v * combi(f, j) % MOD * combi(sum, k - j) % MOD;
            if(ans >= MOD) ans -= MOD;
            //cout << ans << '\n';
        }
        sum += f;
    }
    ans = 1ll * ans * bin_exp(combi(n - 1, k), MOD - 2) % MOD;
    cout << ans << '\n';
}
