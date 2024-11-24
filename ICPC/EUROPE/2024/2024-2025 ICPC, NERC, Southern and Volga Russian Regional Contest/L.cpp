#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int a, b, c;
    a = b = c = n;
    int ans = 0;

    /// (18, 2*21)
    ans += n / 2;
    b -= n / 2;
    c -= n / 2 * 2;
    if(c){
        ans++;
        c--;
        a--;
    }

    ans += a / 2;
    a %= 2;
    if(a){
        ans++;
        b = max(0, b - 1);
    }

    ans += (b + 2) / 3;

    cout << ans << '\n';
}
