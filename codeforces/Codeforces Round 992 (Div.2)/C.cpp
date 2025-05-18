/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second
#define MAXLOG 40

using namespace std;

int64_t pow2[MAXLOG + 1];

void compute_ans(int cur_val, int l, int r, int64_t k, int ans[]){
    if(l == r){
        if(k > 1) ans[0] = -1;
        else ans[l] = cur_val;
        return;
    }

    int len = r - l + 1;
    int64_t perm = pow2[min(MAXLOG, len - 2 )];

    if(k <= perm){
        ans[l] = cur_val;
        compute_ans(cur_val + 1, l + 1, r, k, ans);
    } else {
        ans[r] = cur_val;
        compute_ans(cur_val + 1, l, r - 1, k - perm, ans);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pow2[0] = 1;
    for(int i = 1; i <= MAXLOG; ++i) pow2[i] = pow2[i - 1] * 2;

    int t; cin >> t;
    while(t--){
        int n; int64_t k; cin >> n >> k;
        int ans[n], l = 0, r = n - 1, cur_val = 1;
        while(l < r){
            int64_t perm = pow2[min(MAXLOG, r - l - 1)];

            if(k <= perm) ans[l++] = cur_val++;
            else ans[r--] = cur_val++, k -= perm;
        }
        if(k > 1){
            cout << "-1\n";
            continue;
        }
        ans[l] = n;
        for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    }
}
