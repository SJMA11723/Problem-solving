/**
* Author: Mäthgic Crüe
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

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
#define sz(x) (int)(x).size()

const ll MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int ans[n] = {};
        set<pii> maxsuff;
        for(int i = 1; i <= k; ++i) maxsuff.insert({0, i});

        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            int sum, idx;
            if(x == 1){
                tie(sum, idx) = *maxsuff.begin();
            } else {
                tie(sum, idx) = *maxsuff.rbegin();
            }

            maxsuff.erase({sum, idx});
            sum = max(sum, 0) + x;
            maxsuff.insert({sum, idx});
            ans[i] = idx;
        }

        for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    }
}