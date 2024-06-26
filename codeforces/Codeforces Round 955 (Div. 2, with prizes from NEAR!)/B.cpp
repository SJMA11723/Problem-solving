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
    int t; cin >> t;
    while(t--){
        int64_t x, y, k; cin >> x >> y >> k;

        map<int, int> pasos;

        int p = 0, ciclo = 0;
        while(k){
            int64_t mini;
            if(x % y) mini = min(k, (x + y - 1) / y * y - x);
            else mini = min(k, y);

            k -= mini;
            x += mini;
            p += mini;
            while(x % y == 0) x /= y;

            if(pasos.count(x)){
                ciclo = p - pasos[x];
                k %= ciclo;
            } else pasos[x] = p;
        }

        cout << x << '\n';
    }
}
