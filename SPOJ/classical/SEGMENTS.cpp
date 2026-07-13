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

const int MOD = 1e9 + 7;

struct edge{
    int from, to;
    ll w;
};

bool bellman_ford(int n, vector<edge> &edges){
    vi d(n, 0);
    for(int i = 1; i < n; ++i)
    for(edge &e : edges){
        if(d[e.from] == INT_MAX) continue;
        if(d[e.to] > d[e.from] + e.w){
            d[e.to] = d[e.from] + e.w;
        }
    }
    for(edge &e : edges){
        if(d[e.from] == INT_MAX) continue;
        if(d[e.to] > d[e.from] + e.w){
            return false;
        }
    }
    return true;
}

vector<float> nums;
int idx(float val){
    return lower_bound(all(nums), val) - nums.begin();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<edge> edges;
    vector<pair<float, float>> ranges;
    for(int i = 0; i < n; ++i){
        float a, b; cin >> a >> b;
        ranges.pb({a, b - 0.5});
        nums.pb(a);
        nums.pb(b);
        nums.pb(a + 0.5);
        nums.pb(b - 0.5);
        cin >> b;
    }
    sort(all(nums));
    nums.resize(unique(all(nums)) - nums.begin());

    int l = 1, r = 2 * n;
    while(l < r){
        int mid = l + (r - l) / 2;
        for(int i = 1; i < sz(nums); ++i) edges.pb({i, i - 1, 0});
        for(int i = 0; i < n; ++i){
            int u = idx(ranges[i].fi);
            int v = idx(ranges[i].se);
            edges.pb({v, u, -1});
            edges.pb({u, v, mid});
        }
        if(bellman_ford(sz(nums), edges)) r = mid;
        else l = mid + 1;
        edges.clear();
    }
    cout << l << '\n';
}
