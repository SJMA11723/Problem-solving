/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int64_t P = 31;
const int64_t MOD = 1e9 + 9;
int64_t H[5001], mpow[5001];

void build_hash(string &s){
    H[0] = s[0] - 'a' + 1;
    mpow[0] = 1;
    for(int i = 1; i < s.size(); ++i){
        mpow[i] = mpow[i - 1] * P % MOD;
        H[i] = (H[i - 1] * P + s[i] - 'a' + 1) % MOD;
    }
}

int shash(int i, int j){
    return (H[j] - (i ? H[i - 1] * mpow[j - i + 1] % MOD : 0) + MOD) % MOD;
}

struct suff{
    int idx, ord;
    string s;
    bool operator<(const suff &b){
        return s < b.s;
    }
};

bool comp(const suff &a, const suff &b){
    return a.idx < b.idx;
}

int lcp(int i, int j, vector<suff> &arr){
    int l = 0, r = min(arr[i].s.size(), arr[j].s.size());
    while(l < r){
        int mid = l + (r - l) / 2;
        if(shash(arr[i].idx, arr[i].idx + mid) == shash(arr[j].idx, arr[j].idx + mid)) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        vector<suff> arr;
        for(int i = 0; i < n; ++i) arr.push_back({i, 0, s.substr(i)});
        sort(arr.begin(), arr.end());

        for(int i = 0; i < n; ++i) arr[i].ord = i;

        sort(arr.begin(), arr.end(), comp);

        build_hash(s);

        //cout << shash(0, n - 1) << ' ' << shash(1, n - 1) << ' ' << H[n - 1] << '\n';

        int64_t dp[n] = {};
        for(int i = 0; i < n; ++i){
            dp[i] = 0;
            int idx = -1;
            //cout << i << ' ' << arr[i].s << ' ';
            for(int j = 0; j < i; ++j){
                if(arr[j].ord > arr[i].ord) continue;
                if(dp[i] < dp[j] - lcp(i, j, arr)){
                    idx = j;
                    dp[i] = dp[j] - lcp(i, j, arr);
                }
            }
            dp[i] += n - arr[i].idx;
            //cout << dp[i] << ' ' << idx << ' ' << (idx != -1 ? lcp(i, idx, arr) : 0) << '\n';
        }

        cout << *max_element(dp, dp + n) << '\n';
    }
}
