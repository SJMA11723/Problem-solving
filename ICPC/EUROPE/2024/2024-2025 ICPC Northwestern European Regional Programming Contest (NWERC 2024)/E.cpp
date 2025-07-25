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
#define MAXN 300000
#define INF 100000000
const int MOD = 1e9 + 7;
bool debbb = false;
typedef long long T;
struct pt
{
    T x, y;
    pt(T xx, T yy) : x(xx), y(yy) {}
    pt operator+(pt p) { return {x + p.x, y + p.y}; }
    pt operator-(pt p) { return {x - p.x, y - p.y}; }
    pt operator*(T d) { return {x * d, y * d}; }
    pt operator/(T d) { return {x / d, y / d}; } // only for floatingpoint
};

T sq(pt p) { return p.x * p.x + p.y * p.y; }
double abs(pt p) { return sqrt(sq(p)); }
T dot(pt u, pt v){
    return u.x*v.x+u.y*v.y;
}
double angle(pt v, pt w) {
    double cosTheta = dot(v,w) / abs(v) / abs(w);
    return acos(max(-1.0, min(1.0, cosTheta)));
}


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p){return os << '(' << p.fi << ", " << p.se << ')';}
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream& operator<<(ostream &os, const C &v){string sep; for(const T &x : v) os << sep << x, sep = " "; return os;}
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values){
    cout << "[Debug]\n\t" << vars << " = ";
    string d = "[";
    (..., (cout << d << values, d = "] ["));
    cout << "]\n";
}

int binexp(int x, long long n, int mod){
    if(n == 1) return x%mod;
    else if(n%2 == 0){
        long long t = binexp(x,n/2,mod);
        return (t*t)%mod;
    }
    else{
        return ((long long)x*binexp(x, n-1,mod))%mod;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    int idx = 0;

    string ans = s;
    for(int i = 0; i < n; i++){
        ans[i] = s[idx];
        idx+=binexp(2, k, n);
        idx%=n;
    }

    cout<<ans<<"\n";





    

}