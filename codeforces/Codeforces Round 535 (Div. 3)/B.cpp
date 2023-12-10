/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 10001

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int cub[MAXN] = {};
    int x = 1, y = 1;
    for(int i = 0; i < n; ++i){
        int d; cin >> d;
        cub[d]++;
        x = max(x, d);
    }

    for(int i = 1; i * i <= x; ++i){
        if(x % i == 0){
            cub[i]--;
            if(i * i != x) cub[x / i]--;
        }
    }
    for(int i = 1; i < MAXN; ++i) y = max(y, cub[i] * i);
    cout << x << ' ' << y << '\n';
}
