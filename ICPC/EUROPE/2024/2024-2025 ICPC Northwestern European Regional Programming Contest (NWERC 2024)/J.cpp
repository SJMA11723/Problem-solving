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
typedef vector<pii> vii;
typedef vector<vector<int>> vvi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()
#define DEBUG if(debbb)
#define MAXN 60
#define MAXS 600000


const double PI = acos(-1);
typedef long long T;
typedef complex<T> pt;
#define x real()
#define y imag()
T sq(pt p) {return p.x*p.x + p.y*p.y;}
double abs(pt p) {return sqrt(sq(p));}
template <typename T> int sgn(T x) {
return (T(0) < x) - (x < T(0));
}

long long dp[MAXN][MAXS];

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p){return os << '(' << p.fi << ", " << p.se << ')';}
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream& operator<<(ostream &os, const C &v){string sep; for(const T &xx : v) os << sep << xx, sep = " "; return os;}
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values){
    cout << "[Debug]\n\t" << vars << " = ";
    string d = "[";
    (..., (cout << d << values, d = "] ["));
    cout << "]\n";
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    
    vector<tuple<int,int,pt>> vp;

    for(int i = 0; i < n; i++){
        int h,px,py;
        cin>>px>>py>>h;
        vp.push_back(make_tuple(h, i, pt(px,py)));
    }

    sort(vp.begin(), vp.end(), [](tuple<int,int,pt> a, tuple<int,int,pt>b){
        return get<0>(a) < get<0>(b);
    });
    vector<int> ans(n);
    reverse(vp.begin(), vp.end());
    for(int i = 0; i < n; i++){
        auto [h, idx, a] = vp[i];
        int mind = h;
        for(int j = 0; j < i; j++){
            auto [h2, idx2, b] = vp[j];
            pt d = b-a;
            mind = min((double)mind,abs(d));
        }   
        ans[idx] = mind;
    }

    for(auto a : ans)cout<<a<<"\n";
}