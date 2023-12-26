/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
using namespace std;

int max_match(vector<int> &B, int idx_A[], const int k){
    int res = 0, cnt[k] = {};
    for(int i = 0; i < k; ++i){
        if(idx_A[B[i]] == -1) continue;
        cnt[(i - idx_A[B[i]] + k) % k]++;
    }
    for(int i = 0; i < k; ++i) res = max(res, cnt[i]);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    vector<char> no_ap_a(n + 1, true);
    vector<char> no_ap_b(n + 1, true);
    vector<int> B;
    int idx[n + 1];
    fill(idx, idx + n + 1, -1);

    for(int i = 0; i < k; ++i){
        int a; cin >> a;
        idx[a] = i;
        no_ap_a[a] = false;
    }

    for(int i = 0; i < k; ++i){
        int b; cin >> b;
        B.push_back(b);
        no_ap_b[b] = false;
    }

    int ans = max_match(B, idx, k);
    reverse(B.begin(), B.end());
    ans = max(ans, max_match(B, idx, k));

    for(int i = 1; i <= n; ++i)
        if(no_ap_b[i] && no_ap_a[i]) ans++;
    cout << ans << '\n';
}
