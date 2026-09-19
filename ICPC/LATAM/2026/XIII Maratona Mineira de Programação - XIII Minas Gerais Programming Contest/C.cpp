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

template<typename T> struct max_stack{
    stack<pair<T, T>> st;
    max_stack(){}
    max_stack(const T &MINVAL){init(MINVAL);}
    void init(const T &MINVAL){
        st.push({MINVAL, MINVAL});
    }
    void push(const T &v){
        st.push({v, max(v, st.top().se)});
    }
    T top(){
        return st.top().fi;
    }
    void pop(){
        if(sz(st) > 1) st.pop();
    }
    T maxV(){
        return st.top().se;
    }
    int size(){
        return sz(st) - 1;
    }
    bool empty(){
        return size() == 0;
    }
};

template<typename T> struct max_queue{
    max_queue(const T &MINVAL){
        p_in.init(MINVAL);
        p_out.init(MINVAL);
    }

    void push(const T &v){
        p_in.push(v);
    }

    T front(){
        transfer();
        return p_out.top();
    }

    void pop(){
        transfer();
        p_out.pop();
    }

    int size(){
        return sz(p_in) + sz(p_out);
    }

    T maxV(){
        return max(p_in.maxV(), p_out.maxV());
    }

    bool empty(){
        return size() == 0;
    }

    void transfer(){
        if(sz(p_out)) return;
        while(sz(p_in)){
            p_out.push(p_in.top());
            p_in.pop();
        }
    }

    max_stack<T> p_in, p_out;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int idx[n + 1] = {};
    max_queue<int> q(INT_MIN);
    for(int i = 1; i <= n; ++i){
        int c; cin >> c;
        if(idx[c] > 0){
            while(sz(q) && q.front() != c){
                idx[q.front()] = 0;
                q.pop();
            }
            q.pop();
        }
        idx[c] = i;
        q.push(c);
        cout << q.maxV() << ' ' << idx[q.maxV()] << '\n';
    }
}