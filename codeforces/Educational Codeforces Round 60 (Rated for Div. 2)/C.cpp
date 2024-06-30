/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

__int128_t mabs(__int128_t x){
    return (x < 0 ? -x : x);
}

bool check(int n, pair<int, int> precalc[], __int128_t t, __int128_t a, __int128_t b, __int128_t c, __int128_t d){
    a += (__int128_t)t / n * precalc[n - 1].first + (t % n ? precalc[t % n - 1].first : 0);
    b += (__int128_t)t / n * precalc[n - 1].second + (t % n ? precalc[t % n - 1].second : 0);
    return mabs(a - c) + mabs(b - d) <= t;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int n; cin >> n;
    string s; cin >> s;

    int x = 0, y = 0;
    pair<int, int> precalc[n];
    for(int i = 0; i < n; ++i){
        if(s[i] == 'U') y++;
        else if(s[i] == 'D') y--;
        else if(s[i] == 'L') x--;
        else if(s[i] == 'R') x++;
        precalc[i] = {x, y};
    }

    int64_t l = 0, r = LLONG_MAX;
    while(l < r){
        int64_t mid = l + (r - l) / 2;
        //cout << l << ' ' << r << '\n';
        if(check(n, precalc, mid, a, b, c, d)) r = mid;
        else l = mid + 1;
    }

    cout << (l == LLONG_MAX ? -1 : l) << '\n';

}
