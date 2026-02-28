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
typedef vector<pii> vpii;
typedef vector<pll> vpll;

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

#define DEBUG if(deb)

const bool deb = true;
const int MOD = 1e9 + 7;

/*
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p){
    return os << '(' << p.fi << ", " << p.se << ')';
}
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type> ostream& operator<<(ostream &os, const C &v){
    string sep; for(const T &x : v) os << sep << x, sep = " ";
    return os;
}
#define print(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args> void logger(string vars, Args&&... values){
    cout << "[Debug]\n\t" << vars << " = ";
    string d = "[";
    (..., (cout << d << values, d = "] ["));
    cout << "]\n";
}*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        

        bool ok = true;
        vi ans;
        ordered_set pending;
        int water[n + 1] = {};
        for(int i = 1; i <= m; ++i){
            int d; cin >> d;
            if(!ok) continue;

            if(d){
                auto it = pending.lower_bound({water[d], -1});
                //cout << d << ' ' << it->fi << ' ' << it->se << '\n';
                if(it == pending.end()){
                    ok = false;
                } else {
                    ans[it->se] = d;
                    water[d] = i;
                    pending.erase(it);
                }
            } else {
                pending.insert({i, ans.size()});
                ans.pb(0);
            }
        }

        if(ok){
            cout << "YES\n";
            for(int i = 0; i < sz(ans); ++i) cout << ans[i] << " \n"[i + 1 == sz(ans)];
        } else cout << "NO\n";
    }
}