#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

const int MOD = 1e9 + 7;
bool vis[100010];

void dfs(int node, vector<int>* adyl, vector<int>& comp){
    if(vis[node]) return;
    vis[node] = true;
    comp.push_back(node);

    for(auto edge : adyl[node]){
        dfs(edge, adyl, comp);
    }

    return;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vector<int> adyl[n];
    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        adyl[u].push_back(v);
        adyl[v].push_back(u);
    }
    vector< pair<int, vector<int>> > comps;
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        vector<int> tmp;
        dfs(i, adyl, tmp);
        comps.push_back({tmp.size(), tmp});
    }

    if(comps.size() == 1){
        cout<<"0\n";
        return 0;
    }
    bool flag = false;
    vector<int> thecomp;
    sort(comps.begin(), comps.end());
    reverse(comps.begin(), comps.end());

    int idx = n/2 + n%2;
    if(comps[0].second.size() > n/2){
        idx = comps[0].second.size();
    }

    vector<int> nodes;
    for(auto& comp: comps){
        for(auto& node : comp.second) nodes.push_back(node);
    }
    vector<pair<int,int>> ans;
    for(int i = 0, j = idx; i < n && j < n; i++, j++){
        ans.push_back({nodes[i], nodes[j]});
    }


    int sans = ans.size();

    cout<<sans<<"\n";
    for(auto [a,b] : ans){
        cout<<a<<" "<<b<<"\n";
    }
    


    
}