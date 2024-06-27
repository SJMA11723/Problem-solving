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
    string recipe; cin >> recipe;
    int64_t s, b, c; cin >> b >> s >> c;
    int64_t pb, ps, pc; cin >> pb >> ps >> pc;
    int64_t R; cin >> R;

    int64_t nb = 0, ns = 0, nc = 0;
    for(char c : recipe){
        if(c == 'B') nb++;
        else if(c == 'S') ns++;
        else nc++;
    }

    int64_t l = 0, r = 1e14;
    while(l < r){
        int64_t mid = l + (r - l) / 2;
        if(max(0ll, mid * nb - b) * pb + max(0ll, mid * ns - s) * ps + max(0ll, mid * nc - c) * pc > R) r = mid;
        else l = mid + 1;
    }
    cout << l - 1 << '\n';
}

