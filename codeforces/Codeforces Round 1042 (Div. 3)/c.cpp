/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        map<int, int> S, T;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            S[x % k]++;
        }
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            T[x % k]++;
        }

        for(auto it = S.begin(); it != S.end(); ++it){
            if(it->se > T[it->fi]){
                if(it->fi == k - it->fi) break;
                S[k - it->fi] += it->se - T[it->fi];
                it->se = T[it->fi];
            }
        }
        cout << (S == T ? "YES\n" : "NO\n");
    }
}
