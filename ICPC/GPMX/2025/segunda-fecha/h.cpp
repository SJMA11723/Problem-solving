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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;

struct point{
    int x, y;
    bool t;

    ll normsq(){
        return 1ll * x * x + 1ll * y * y; 
    }

    point operator-(point &b){
        return {x - b.x, y - b.y, 0};
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    short n;
    ll h, k;
    cin >> n >> h >> k;
    h *= h;
    k *= k;

    vector<short> graph[n];
    point arr[n];
    bool dest[n] = {};
    for(short i = 0; i < n; ++i){
        cin >> arr[i].x >> arr[i].y >> arr[i].t;
        
        if(arr[i].t && 1ll * arr[i].y * arr[i].y <= h)
            dest[i] = 1;

        for(short j = 0; j < i; ++j){
            point d = arr[i] - arr[j];
            if(arr[i].t){
                if(arr[j].t && d.normsq() <= max(h, k)){
                    graph[i].pb(j);
                    graph[j].pb(i);
                } else if(!arr[j].t && d.normsq() <= h){
                    graph[i].pb(j);
                }
            } else if(arr[j].t && d.normsq() <= k){
                graph[i].pb(j);
            }

            if(arr[j].t && !arr[i].t && d.normsq() <= h)
                graph[j].pb(i);
            if(!arr[j].t && arr[i].t && d.normsq() <= k){
                graph[j].pb(i);
            }
        }
    }

    int a, b; cin >> a >> b;
    short s = -1;
    for(short i = 0; i < n; ++i)
    if(arr[i].x == a && arr[i].y == b){
        s = i;
        break;
    }

    if(arr[s].y == 0){
        cout << "0\n";
        return 0;
    } else if(dest[s]){
        cout << "1\n";
        return 0;
    }

    unsigned short vis[n] = {};
    queue<short> q;
    vis[s] = 1;
    q.push(s);
    while(q.size()){
        short u = q.front();
        q.pop();

        if(arr[u].y == 0){
            cout << vis[u] - 1 << '\n';
            return 0;
        }

        for(short v : graph[u]){
            if(vis[v]) continue;
            if(dest[v]){
                cout << vis[u] + (arr[v].y != 0) << '\n';
                return 0;
            }
            vis[v] = vis[u] + 1;
            q.push(v);
        }
    }
    cout << "-1\n";
}
