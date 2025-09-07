#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    long long ans = 0;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        ans += 1ll * x * i * (n - i + 1);
    }
    cout << ans << '\n';
}