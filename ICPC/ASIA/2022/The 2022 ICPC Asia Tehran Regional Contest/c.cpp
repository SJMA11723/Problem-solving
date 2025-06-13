#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define INF 20000000000
#define MAXN 2010

bool vis[MAXN];
int dist[MAXN];

const int64_t MOD = 1e9 + 7;


bool intersect(pair<double, double> a, pair<double, double> b, pair<double, double>& out){
    auto [l1,r1] = a;
    auto [l2,r2] = b;
    
    out = {max(l1,l2), min(r1,r2)};
    if(out.first > out.second) return false;
    return true; 

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    vector<pair<int,int>> v;

    for(int x = 0; x < n; x++){
        int px,py;
        cin>>px>>py;
        v.pb({px,py});
    }
    int delta;
    cin>>delta;

    sort(v.begin(), v.end());
    vector<vector<int>> adyl(n, vector<int>());
    
    for(int i = 0; i < n; i++){
        pair<double, double> ival = {-INF, INF};
        auto [px, py] = v[i];
        for(int j = i+1; j < n; j++){
            auto [l, r] = ival;
            auto [qx, qy] = v[j];
            double m = ((double)(qy-py))/(qx-px);
            double mup = ((double)(qy-py+delta))/(qx-px);
            double mdown =  ((double)(qy-py-delta))/(qx-px);
            if(l <= m && m <= r){
                adyl[i].pb(j);
            }
            if(!intersect({mdown, mup}, {l, r}, ival )) break;
        }
    }

    
    queue<pair<int,int>> q;
    
    q.push({0,1});
    vis[0] = true;
    while(!q.empty()){
        auto [u, d] = q.front();
        q.pop();
        dist[u] = d;
        for(auto v : adyl[u]){
            if(!vis[v]) {
                vis[v] = true;
                q.push({v, d+1});
            }
        }
    }

    cout<<dist[n-1]<<"\n";


}