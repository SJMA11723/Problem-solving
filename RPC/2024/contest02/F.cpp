#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t n, c, x, s = 0, ans, mini = LLONG_MAX;
    cin >> n >> c;
    ans = n;
    for(int i = 0; i < n; i++){
        cin >> x;
        s += x;
        if((s + c) / c < mini && (s + c) / c <= (n - i)){
            mini = (s + c) / c;
            ans = i;
        }
        s = max((int64_t)0, s - c);
    }

    if(ans == n) cout << "impossible\n";
    else cout << ans << '\n';

    return 0;
}
