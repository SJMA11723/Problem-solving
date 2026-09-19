#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define pb push_back
#define fi first
#define se second

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

const int MOD = 1e9 + 7;

// =============== DEBUG ============
const bool deb = 0;
#define DEBUG if(deb)

template<typename A, typename B> ostream & operator<<(ostream &os, const pair<A, B> &p){
    return os << '(' << p.fi << ", " << p.se << ')';
}
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream & operator<<(ostream &os, const C &v){
    string sep;
    for(const T &x : v) os << sep << x, sep = " ";
    return os;
}
#define print(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename ...Args> void logger(string vars, Args&&... values){
    cout << "[Debug]\n\t" << vars << " = ";
    string d = "[";
    (..., (cout << d << values, d = "] ["));
    cout << "]\n";
}
// ==================================

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q; 
    int masks[n];  
    for(int i = 0; i < n; i++){
        int ns;
        cin>>ns;
        int mask = 0;
        for(int j = 0; j < ns; j++){
            int bs; 
            cin>>bs;
            bs--;
            mask|=(1 << bs);
        }
        masks[i] = mask;
    }
    vector<int> adyl[m];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < i; j++){
            bool flag = false;
            for(int x = 0; x < n; x++){
                int mask = masks[x];
                if(mask & (1<< i) && mask & (1 << j)) flag = true;
            }
            if(flag) {
                adyl[i].push_back(j);
                adyl[j].push_back(i);
            }
        }
    }

    //floyd warsh

    const int INF = 2e9;
    vvi d(m, vi(m, INF));

    for(int node = 0; node < m; node++){
        for(auto edge : adyl[node]){
            d[node][edge] = 1;
            d[edge][node] = 1;
        }
    }

    for(int k = 0; k< m; k++){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                if(d[i][k] == INF || d[k][j] == INF) continue;
                if(d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k]+d[k][j];
            }
        }
    }
    //print(d);
    while(q--){
        
        int a, b;
        cin>>a>>b;
        
        a--;
        b--;
       // print(a,b);
        if(masks[a] & masks[b]) cout<<"0\n";
        else{
            
            vector<int> langsA, langsB;
            for(int i = 0; i < 30; i++) if(masks[a] & (1 << i)) langsA.pb(i);
            for(int i = 0; i < 30; i++) if(masks[b] & (1 << i)) langsB.pb(i);

            int ans = INF;
            for(auto from : langsA){
                for(auto to: langsB){
                    ans = min(ans, d[from][to]);
                }
            }
            if(ans == INF) cout<<"-1\n";
            else cout<<ans<<"\n";
        }
    }









}