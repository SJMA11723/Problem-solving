#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = (a); i < (b); ++i)

const int MOD = 1e9 + 7;


ll lcm(int a, int b){
    return ((ll)a*b)/__gcd(a,b);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin>>n>>k;
    vector<vector<int>> vv;
    for(int i = 0; i < k; i++)vv.push_back(vector<int>());
    for(int i = 0, idx = 0; i < n; i++, idx++){
        idx%=k;
        vv[idx].push_back(i);
    }
    vector<int> vals;

    
    reverse(vv.begin(), vv.end());
    for(auto& v: vv){
        for(auto& x : v) vals.push_back(x);
    }
    reverse(vals.begin(), vals.end());
    /*for(auto x: vals){
        cout<<x<<" ";
    }   
    cout<<"\n";*/
    int perm[n];
    for(int i = 0; i < n; i++){
        perm[vals[i]] = i;
    }
    vector<bool> vis(n, false);
    vector<int> sizes;
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        int next = perm[i];
        int cnt = 0;
        while(!vis[next]){
            vis[next] = true;
            next = perm[next];
            cnt++;
        }
        sizes.push_back(cnt);
    }
    ll ans = 1;
    for(auto x : sizes){
        ans = lcm(x, ans);
    }
    cout<<ans<<"\n";
}