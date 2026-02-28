#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vii;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()

mt19937_64 generator(chrono::steady_clock::now().time_since_epoch().count());

uniform_int_distribution<ll> distr(1, 1e18);

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    map<string, vector<int>> m;


    for(int i = 0; i < n; i++){
        for(int j = 1; j <= 10; j++){
            string s;
            cin>>s;

            if(!m.count(s)) m.insert({s, vector<int>(11, 0)});
            m[s][0]++;
            m[s][j]++;
        }
    }


    vector<pair<vector<int>, string>> vs;

    for(auto [s, v] : m){
        vs.push_back({v,s});
    }


    sort(vs.begin(), vs.end());

    if(sz(vs) == 1){
        cout<<vs[0].second<<"\n";
        return 0;
    }

    
    auto [v1, s1] = vs[sz(vs)-1];
    auto [v2, s2] = vs[sz(vs)-2];

    for(int i = 0; i <= 10; i++){
        if(v1[i] != v2[i]){
            cout<<s1<<"\n";
            return 0;
        }
    }

    cout<<"tie\n";

}