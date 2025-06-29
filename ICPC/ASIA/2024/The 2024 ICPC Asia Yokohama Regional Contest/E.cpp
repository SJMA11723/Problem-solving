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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()s
#define pb push_back
#define sz(x) (int)(x).size()
#define NMAX 51
#define DEBUG if(debbb)
bool debbb = false;
const int MOD = 1e9 + 7;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n,m;

char ch[NMAX*NMAX+1];
int id(int px, int py){
    return px*(m)+py;
}
bool vis[NMAX][NMAX];
void dfs(int px, int py, int prev, vector<int>* adyl, string* mat){
    if(px < 0 || py < 0 || px >= n|| py >= m || vis[px][py] || mat[px][py] == '.') return;
    vis[px][py] = true;
    int idd = id(px, py);
    ch[idd] = mat[px][py];
    if(prev != -1) adyl[prev].push_back(idd);
    DEBUG printf("%d %d %d %c (%d %d) (%d -> %d)\n", px, py, prev, mat[px][py], n, m, prev, idd);
    for(int i = 0; i < 4; i++){
        int nx = px+dx[i];
        int ny = py+dy[i];
        dfs(nx, ny, idd, adyl, mat);
    }
    return;
}

ll build(int node, vector<int>* adyl){
    DEBUG printf("%d\n",node);
    
    if(ch[node] == 'P' || ch[node] == '#'){
        ll val =build(adyl[node][0], adyl);
        DEBUG printf("%d %d\n",node, val);
        return val;
    }
    else if(ch[node] == '+'){
        ll val = build(adyl[node][0], adyl)+build(adyl[node][1], adyl);
        DEBUG printf("%d %d\n",node, val);
        return val;
    }
    else if(ch[node] == '-'){
        ll a = build(adyl[node][0], adyl);
        ll b = build(adyl[node][1],adyl);
        ll val = max(a,b)-min(a,b);
        return val;
    }
    else if(ch[node] == '*'){

        ll val = build(adyl[node][0], adyl)*build(adyl[node][1], adyl);
        DEBUG printf("%d %d\n",node, val);
        return val;
    }
    else if(ch[node] == '/'){
        ll a = build(adyl[node][0], adyl);
        ll b = build(adyl[node][1],adyl);
        ll val = max(a,b)/min(a,b);
        DEBUG printf("%d %d\n",node, val);        
        return val;
    }
    else{
        DEBUG printf("%d %d\n",node, ch[node]-'0');
        return ch[node]-'0';
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;

    string mat[n];

    for(int x = 0; x < n; x++) cin>>mat[x];

    int px,py;

    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            if(mat[x][y] == 'P'){px = x; py = y;}
        }
    }
    DEBUG printf("A %d %d\n", px, py);
    vector<int> adyl[n*m+1];
    dfs(px, py, -1, adyl, mat);
    DEBUG printf("A %d %d\n", px, py);
    long long ans = build(id(px, py), adyl);
    cout<<ans<<"\n";
}
