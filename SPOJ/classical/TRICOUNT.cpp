/**
 Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    uint64_t ans[MAXN + 1];
    ans[0] = 0;
    for(uint64_t i = 1; i <= MAXN; ++i) ans[i] = ans[i - 1] + i * (i + 1) / 2 + (i / 2) * (i / 2 + 1) - ((i - 1) % 2) * (i / 2);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << ans[n] << '\n';
    }
}
