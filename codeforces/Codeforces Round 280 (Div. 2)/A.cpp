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
    int n; cin >> n;
    int ans = 0, cnt = 0, sum = 0;
    while(cnt + sum + ans + 1 <= n) sum += ++ans, cnt += sum;
    cout << ans << '\n';
}
