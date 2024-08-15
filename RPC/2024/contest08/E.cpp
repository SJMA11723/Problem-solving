
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        int a, b; cin >> a >> b;
        ans = max(ans, 1ll * a * b * min(a, b));
    }
    cout << ans << '\n';
}
