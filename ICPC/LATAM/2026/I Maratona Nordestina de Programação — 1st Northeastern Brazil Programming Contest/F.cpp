#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
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
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

const int MOD = 1e9 + 7;

template<typename A, typename B> ostream&operator<<(ostream &os, const pair<A, B> &p){
    return os << '(' << p.fi << ", " << p.se << ')';
}
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream& operator<<(ostream &os, const C &v){
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

const bool deb = 0;
#define DEBUG if(deb)

typedef long long T;
typedef complex<T> pt;

#define x real()
#define y imag()
#define INF 1e18
T sq(pt p){return p.x*p.x+p.y*p.y;}
ld abs(pt p){return sqrtl(sq(p));}

struct circle{
    pt o;
    int r;
    circle(pt o, int r){
        this->o = o;
        this->r = r;
    }
};

struct edge{
    int from, to;
    ld w;
    edge(int from, int to, ld w){
        this->from = from;
        this->to = to;
        this->w = w;
    }
    const bool operator< (const edge&b)const{
        return w > b.w;
    }
};

struct pos{
    int from;
    ld c;
    const bool operator<(const pos&b) const{
        return c > b.c;
    }
};

ld dijskstra(int a, int b, vector<edge> graph[], int n){
    n+=2;
    ld dist[n];
    bool vis[n] = {};
    fill(dist, dist+n, INF);

    priority_queue<pos> q;
    q.push(pos{a, 0}); dist[a] = 0;
    while(sz(q)){
        pos cur = q.top(); q.pop();
        if(vis[cur.from]) continue;
        vis[cur.from] = true;
        for(edge & e: graph[cur.from]){
            if(dist[e.to] <= dist[e.from]+e.w) continue;
            dist[e.to] = dist[e.from] + e.w;
            q.push(pos{e.to, dist[e.to]});
        }
    }
    return dist[b];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,h;
    cin>>n>>h;
    vector<circle> vc;
    for(int i = 0; i < n; i++){
        int px, py,r;
        cin>>px>>py>>r;
        circle c(pt(px,py),r);
        vc.pb(c);
    }
    
    vector<edge> adyl[n+2];
    int i = 0;
    for(circle c : vc){
        int px = c.o.x;
        int py = c.o.y;
        int r = c.r;
        int dis = max(0, py-r);
        adyl[n].push_back(edge(n,i, dis));
        dis = max(h-py-r, 0);
        adyl[i].push_back(edge(i,n+1,dis));
        i++;
    }
    adyl[n].push_back(edge(n, n+1, h));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            circle c1 = vc[i], c2 = vc[j];
            pt dv = c1.o - c2.o;
            ld du = abs(dv);
            ld dis = max(du-(c1.r+c2.r), (ld)0);
            adyl[i].push_back(edge(i,j, dis));
            adyl[j].push_back(edge(j,i, dis));
        }
    }

    ld ans = dijskstra(n, n+1, adyl, n);

    cout<<setprecision(8)<<fixed<<ans<<"\n";




}