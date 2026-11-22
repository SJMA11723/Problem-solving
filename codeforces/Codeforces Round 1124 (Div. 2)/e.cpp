/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/
#include <bits/stdc++.h>
using namespace std;
// typedef
typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

// define
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define repr(i,a,b) for(int i = (b) - 1; (a) <= i; --i)
const int MOD = 1e9 + 7;

// --- --- --- --- EXTTRAS --- --- --- --- 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef __int128_t lll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937_64 seed(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> ale(1, LLONG_MAX);


// --- --- --- --- LOGGER SETUP --- --- --- --- 
// Daclare before   
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream& operator<<(ostream &os, const C &v);
// Overload for std::pair
template<typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.fi << ", " << p.se << ')';
}
// Overload for Containers (excluding std::string) SFINAE
template<typename C, typename T>
ostream& operator<<(ostream &os, const C &v) {
    string sep;
    for(const T &x : v) os << sep << x, sep = " ";
    return os;
}
// Colors
constexpr const char *RST="\033[0m", *GREEN="\033[1;32m", 
*YELLOW="\033[1;33m",*CYAN="\033[1;36m",*RED="\033[1;31m";
// Logger Function
template<typename ...Args>
void logger(const char* col, string vars, Args&&... values){
    cerr << col << '[' << vars << "] =" << RST;
    ((cerr << " [" << values << ']'), ...);
    cerr << '\n';
}

// --- --- --- --- DEBUGGER SETUP --- --- --- ---    
#ifdef LOCAL
    #define DEBUG   if (true)
    #define SALTO   (cerr << '\n')  
    #define LOG(...)   logger("", #__VA_ARGS__, __VA_ARGS__)
    #define LOGC(c, ...) logger(c, #__VA_ARGS__, __VA_ARGS__)    
    #define COL(c, ...) (cerr << c << __VA_ARGS__ << RST << '\n')
#else
    #define DEBUG   if (false) 
    #define SALTO
    #define LOG(...)
    #define LOGC(...)
    #define COL(...)
#endif

#define LOGN 17
#define MAXN (1 << 18)

int cnt[MAXN + 1];
vi touched;

// si esto pasa en tiempo entonces me hace falta aprender C++
bool dfs(int u, pii T[], int L[], int R[], int  arr[], int pref[], int mask){
    if(!u) return 0;

    if(T[u] == pii(0, 0)){
        cnt[pref[u] & mask]++;
        touched.pb(pref[u] & mask);
        return 0;
    }

    // small to large
    if(u - L[u] < R[u] - u){
        if(dfs(T[u].fi, T, L, R, arr, pref, mask)) return 1;
        for(int x : touched) cnt[x] = 0; touched.clear();
        if(dfs(T[u].se, T, L, R, arr, pref, mask)) return 1;

        LOG("izq -> der");
        if((mask & arr[u]) == mask) rep(i, L[u], u)
            if(cnt[(pref[i] & mask) ^ mask] || (i + 1 < u && ((pref[u] ^ pref[i]) & mask) == mask))
                return 1;
        rep(i, L[u] + 1, u + 1){
            cnt[pref[i] & mask]++;
            touched.pb(pref[i] & mask);
        }
        return 0;
    } else {
        if(dfs(T[u].se, T, L, R, arr, pref, mask)) return 1;
        for(int x : touched) cnt[x] = 0; touched.clear();
        if(dfs(T[u].fi, T, L, R, arr, pref, mask)) return 1;

        LOG("izq <- der");
        LOG(L[u], u, R[u]);
        if((mask & arr[u]) == mask){
            rep(i, u + 1, R[u]){
                if(cnt[(pref[i] & mask) ^ mask] || ( ((pref[i] ^ pref[L[u]]) & mask) == mask ))
                    return 1;
            }
            cnt[pref[u - 1] & mask]--;
            if(cnt[(pref[u] & mask) ^ mask] || (L[u] + 1 < u && ( (pref[u] ^ pref[L[u]]) & mask ) == mask ))
                return 1;
            cnt[pref[u - 1] & mask]++;
        }
        rep(i, u, R[u]){
            cnt[pref[i] & mask]++;
            touched.pb(pref[i] & mask);
        }
        return 0;
    }
}

int main(){
    #ifdef LOCAL
        ifstream cin("test.in");
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n + 1]; arr[0] = 0;
        int pref[n + 1]; pref[0] = 0;
        rep(i, 1, n + 1){
            cin >> arr[i];
            pref[i] = arr[i] ^ pref[i - 1];
        }
        stack<int> st;
        int L[n + 1] = {}, R[n + 1]; fill(R, R + n + 1, n + 1);
        rep(i, 1, n + 1){
            while(sz(st) && arr[st.top()] < arr[i]){
                R[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(sz(st)) st.pop();
        repr(i, 1, n + 1){
            while(sz(st) && arr[i] >= arr[st.top()]){
                L[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(sz(st)) st.pop();
        
        // cartesian tree (yo esperaba un treap pero algo es algo)
        pii T[n + 1];
        int root = 0;
        rep(i, 1, n + 1){
            int vl = L[i] ? arr[L[i]] : INT_MAX;
            int vr = R[i] <= n ? arr[R[i]] : INT_MAX;
            if(min(vl, vr) == INT_MAX) root = i;
            else if(min(vl, vr) == vr) T[R[i]].fi = i;
            else T[L[i]].se = i;
        }

        int ans = 0;
        repr(i, 0, LOGN + 1){
            if(dfs(root, T, L, R, arr, pref, ans | (1 << i)))
                ans |= 1 << i;
        }
        cout << ans << '\n';
    }
}

// voyallorar