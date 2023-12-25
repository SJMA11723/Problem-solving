/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_power_of_two(S) (!((S) & ((S) - 1)))
#define lsb(S) (S & (-S))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t n, k; cin >> n >> k;
    int64_t ans = 0;
    ans = n;
    while(!is_power_of_two(n)) n -= lsb(n);
    if(k > 1) ans = 2 * n - 1;
    cout << ans << '\n';
}
