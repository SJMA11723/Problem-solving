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
    long long n;
    int k;
    cin >> n >> k;
    int cnt2 = 0, cnt5 = 0;
    int tmp = n;
    while(tmp % 2 == 0) tmp /= 2, cnt2++;
    while(tmp % 5 == 0) tmp /= 5, cnt5++;

    int mini = min(cnt2, cnt5);
    k = max(0, k - mini);
    cnt2 -= mini;
    cnt5 -= mini;
    long long ans = n;

    mini = min(k, cnt5);
    for(int i = 0; i < mini; ++i) ans *= 2;
    k -= mini;
    cnt5 -= mini;

    mini = min(k, cnt2);
    for(int i = 0; i < mini; ++i) ans *= 5;
    k -= mini;
    cnt2 -= mini;

    for(int i = 0; i < k; ++i) ans *= 10;
    cout << ans << '\n';
}
