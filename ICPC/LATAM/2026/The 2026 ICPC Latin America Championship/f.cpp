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
typedef vector<vll> vpll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define all(x) (x).begin, (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p){
    return os << '(' << p.fi << ", " << p.se << ')';
}

template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream& operator<<(ostream &os, const C &v){
    string sep;
    for(const T &x : v) os << sep << x, sep = " ";
    return os;
}

#define PRINT(...) logger(#__VA_ARGS__, __VA_ARGS__)

template<typename ...Args>
void logger(string vars, Args&&... values){
    cout << "[Debug]\n\t" << vars << " = ";
    string d = "[";
    (..., (cout << d << values, d = "] ["));
    cout << "\n";
}
#define DEBUG if(debb)

bool debb = false;
const int MOD = 1e9 + 7;


int mat[18][18];
bool vis[18][18];

void clear(){
    for(int i = 0; i < 18; i++)for(int j = 0; j < 18; j++) mat[i][j] = vis[i][j] =0; 
}
void print(){
    for(int i = 0; i < 18; i++){for(int j = 0; j < 18; j++) {cout<<mat[i][j];}cout<<"\n";}
}


void paint(int i, int j, int v, vector<int>& stripe){
    int cnt = stripe.size();
    if(v){
        for(int x = 0; x < cnt; x++){
            mat[i+x][j] = stripe[x];
        }
    }
    else{
        for(int y = 0; y < cnt; y++){
            mat[i][j+y] = stripe[y];
        }
    }
}


int dfs(int val, int pi, int pj, int n){
    
    if(pi < 0 || pj < 0 || pi >= n || pj >= n || mat[pi][pj] != val|| vis[pi][pj]) return 0;
    DEBUG PRINT("dfs", val, pi, pj);
    vis[pi][pj] = 1;

    int dx[] = {1, 1, -1, -1, 0, 0};
    int dy[] = {0, -1, 0,  1, 1, -1};
    int cnt = 1;
    for(int d = 0; d < 6; d++){
        cnt+= dfs(val, pi+dx[d], pj+dy[d], n);
    }
    return cnt;
}


int floodfill(int n){

    int maxi = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!mat[i][j] || vis[i][j]) continue;
            DEBUG PRINT("nxt", mat[i][j]);
            int cnt = dfs(mat[i][j],i, j, n);
            maxi = max(maxi, cnt);
        }
    }
    return maxi;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> stripes[18];
    int lim = 1;
    for(int i = 0; i < n; i++){
        if(stripes[lim-1].size() >= lim)lim++;
        int t;
        cin>>t;
        stripes[lim-1].push_back(t);
    }

    while(stripes[lim-1].size() < lim)stripes[lim-1].push_back(0);
    for(auto& stripe : stripes) reverse(stripe.begin(), stripe.end());

    int ans = 0;
    for(int mask = 0; mask < (1 << lim); mask++){
        clear();
        int currx=0, curry=0;
        for(int i = lim-1; i >= 0; i--){
            if(mask & (1<<i)){
                //1 vert
                paint(currx, curry, 1, stripes[i]);
                curry++;
            }
            else{
                paint(currx, curry, 0, stripes[i]);
                currx++;
            }
        }
        DEBUG {
            PRINT(mask, stripes);
            cout<<"*\n\n";
            print();
            
        }
        int cnt = floodfill(lim);
        ans = max(ans, cnt);
    }

    cout<<ans<<"\n";







}
