/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, p; cin >> n >> p;
    long double ans = 0;
    int l[n], r[n];
    for(int i = 0; i < n; ++i) cin >> l[i] >> r[i];
    for(int i = 0; i < n; ++i){
        int mpi = r[i] / p - (l[i] - 1) / p;
        int mpj = r[(i + 1) % n] / p - (l[(i + 1) % n] - 1) / p;
        ans += 2000 * (1 - (long double)(r[i] - l[i] + 1 - mpi) * (r[(i + 1) % n] - l[(i + 1) % n] + 1 - mpj) / (1ll * (r[i] - l[i] + 1) * (r[(i + 1) % n] - l[(i + 1) % n] + 1)));
    }
    cout << fixed << setprecision(6) << ans << '\n';
}
