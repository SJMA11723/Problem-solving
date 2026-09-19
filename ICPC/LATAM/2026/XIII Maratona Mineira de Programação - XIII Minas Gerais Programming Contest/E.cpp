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

    int n, m, t;
    cin>>n>>m>>t;
    int mat[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>mat[i][j];
        }
    }

    int dx[] = {1,-1, 0, 0, 0};
    int dy[] = {0, 0, 1, -1, 0};


    vector<pair<int,int>> pA, pB;

    for(int i = 0; i < t; i++){
        int px, py;
        cin>>px>>py;
        px--;
        py--;
        pA.pb({px,py});
    }
    for(int i = 0; i < t; i++){
        int px, py;
        cin>>px>>py;
        px--;
        py--;
        pB.pb({px,py});
    }   
    long long ans[] = {0,0};
    for(int i = 0; i < t; i++){
        //print(i);
        map<pair<int,int>, int> freqs;
        vector<pair<pair<int,int>, int>> coords;
        for(int j = 0; j < 5; j++){
            auto [ax, ay] = pA[i];
            ax+=dx[j];
            ay+=dy[j];
            freqs[{ax,ay}]++;
            coords.push_back({{ax,ay}, 0});
            auto [bx, by] = pB[i];
            bx+=dx[j];
            by+=dy[j];
            freqs[{bx, by}]++;
            coords.push_back({{bx,by}, 1});
        }
        //print(coords);

        for(auto [coord, p] : coords){
            auto [px, py] = coord;
            if(freqs[{px,py}] > 1 || min(px, py) < 0 || px >= n || py >= m) continue;
            //print(coord, p);
            ans[p]+=mat[px][py];
            mat[px][py] = 0;
        }
    }
    cout<<ans[0]<<" "<<ans[1]<<"\n";
}