/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

using namespace std;

const uint64_t p = 31, p2 = 37, p3 = 41;
const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<tuple<int, int, int>, int> cnt;
    int n; cin >> n;
    string arr[n];
    int64_t ans = 0;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];

        int mhash = 0, mhash2 = 0, mhash3 = 0;
        for(char c : arr[i]){
            mhash = (1ll * mhash * p + c - 'a' + 1) % MOD;
            mhash2 = (1ll * mhash2 * p2 + c - 'a' + 1) % MOD;
            mhash3 = (1ll * mhash3 * p3 + c - 'a' + 1) % MOD;
            cnt[{mhash, mhash2, mhash3}]++;
        }

        ans += arr[i].size();
    }
    ans *= 2 * n;

    for(string &s : arr){
        int mhash = 0, mhash2 = 0, mhash3 = 0;
        for(int i = (int)s.size() - 1; 0 <= i; --i){
            mhash = (1ll * mhash * p + s[i] - 'a' + 1) % MOD;
            mhash2 = (1ll * mhash2 * p2 + s[i] - 'a' + 1) % MOD;
            mhash3 = (1ll * mhash3 * p3 + s[i] - 'a' + 1) % MOD;
            if(cnt.count({mhash, mhash2, mhash3})) ans -= 2ll * cnt[{mhash, mhash2, mhash3}];
        }
    }
    cout << ans << '\n';
}
