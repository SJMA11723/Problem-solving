#include <bits/stdc++.h>

using namespace std;

int64_t sum_sq(int64_t n){
    int64_t res = 0;
    while(n){
        res += 1ll * (n % 10) * (n % 10);
        n /= 10;
    }
    return res;
}

int64_t funniness(int64_t n){
    set<int64_t> ap;
    int64_t res = n;
    while(!ap.count(n)){
        res = min(res, n);
        ap.insert(n);
        n = sum_sq(n);
        res = min(res, n);
    }
    res = min(res, n);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b; cin >> a >> b;

    int64_t memo[487] = {};
    for(int i = 1; i <= 486; ++i) memo[i] = funniness(i);

    int64_t ans = 0, ans2 = 0;
    for(int i = a; i <= b; ++i) ans += min(1ll*i, memo[sum_sq(i)]);
    cout << ans << '\n';
}
