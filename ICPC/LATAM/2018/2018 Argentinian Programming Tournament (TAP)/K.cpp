#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to;
    long double w;
};

void dfs(int u, vector<edge> tree[], long double dp[], long double dp2[], int dp_size[], int p = -1){
    dp_size[u] = 1;
    dp[u] = 0;
    dp2[u] = 0;
    for(edge &e : tree[u]){
        int v = e.to;
        if(v == p) continue;

        dfs(v, tree, dp, dp2, dp_size, u);
        dp_size[u] += dp_size[v];
        dp[u] += dp[v] + e.w * dp_size[v];
        dp2[u] += dp_size[v] * e.w * e.w + 2 * e.w * dp[v] + dp2[v];
    }
}

void dfs_reroot(int u, vector<edge> tree[], long double dp[], long double dp2[], int dp_size[], long double &ans, int p = -1){
    for(edge &e : tree[u]){
        int v = e.to;

        long double w = e.w;
        int a = dp_size[u] - dp_size[v];
        int b = dp_size[v];
        long double sv = dp[v];
        long double sv2 = dp2[v];
        long double su = dp[u] - (dp[v] + w * dp_size[v]);
        long double su2 = dp2[u] - (dp_size[v] * e.w * e.w + 2 * e.w * dp[v] + dp2[v]);

        //cout << "Llega " << u << ' ' << v << '\n';

        //cout << su2 << ' ' << su << ' ' << a << ' ' << sv2 << ' ' << sv << ' ' << b << '\n';
        long double x = 0;
        ans = min(ans, su2 + 2 * x * su + a * x * x + sv2 + 2 * (w - x) * sv + b * (w - x) * (w - x));
        //cout << "x = " << x << ' ' << fixed << setprecision(5) << ans << '\n';

        x = w;
        ans = min(ans, su2 + 2 * x * su + a * x * x + sv2 + 2 * (w - x) * sv + b * (w - x) * (w - x));
        //cout << "x = " << x << ' ' << fixed << setprecision(5) << ans << '\n';

        x = (sv - su + b * w) / (a + b);
        if(0 <= x && x <= w) ans = min(ans, su2 + 2 * x * su + a * x * x + sv2 + 2 * (w - x) * sv + b * (w - x) * (w - x));
        //cout << "x = " << x << ' ' << fixed << setprecision(5) << ans << '\n';

        if(v == p) continue;

        int dp_szu = dp_size[u];
        long double dpu = dp[u];
        long double dp2u = dp2[u];
        long double dp_szv = dp_size[v];
        long double dpv = dp[v];
        long double dp2v = dp2[v];

        dp_size[u] -= dp_size[v];
        dp[u] -= dp[v] + e.w * dp_size[v];
        dp2[u] -= dp_size[v] * e.w * e.w + 2 * e.w * dp[v] + dp2[v];
        dp_size[v] += dp_size[u];
        dp[v] += dp[u] + e.w * dp_size[u];
        dp2[v] += dp_size[u] * e.w * e.w + 2 * e.w * dp[u] + dp2[u];

        dfs_reroot(v, tree, dp, dp2, dp_size, ans, u);

        dp_size[u] = dp_szu;
        dp_size[v] = dp_szv;
        dp[u] = dpu;
        dp[v] = dpv;
        dp2[u] = dp2u;
        dp2[v] = dp2v;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<edge> tree[n];
    for(int i = 1; i < n; ++i){
        int a, b;
        long double w;
        cin >> a >> b >> w;
        a--, b--;
        tree[a].push_back({a, b, w});
        tree[b].push_back({b, a, w});
    }

    int dp_size[n];
    long double dp[n], dp2[n], ans = numeric_limits<long double>::max();
    dfs(0, tree, dp, dp2, dp_size);
    dfs_reroot(0, tree, dp, dp2, dp_size, ans);

    int cnt = 0;
    while(ans >= 10){
        cnt++;
        ans /= 10;
    }
    cout << fixed << setprecision(5) << ans << ' ' << cnt << '\n';
}
