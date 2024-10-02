#include <bits/stdc++.h>

using namespace std;

int64_t S(int n){
    return 1ll * n * (n + 1) / 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t n; cin >> n;
    int ans = 0, last = 0;
    for(int i = 1; 2 * S(i - 1) + i <= n; ++i) last = i;
    cout << 2 * last - 1 + (n - (2 * S(last - 1) + last) + last - 1) / last << '\n';
}
