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
        long long n, p, l, a;
        cin >> n >> p >> l >> a;
        long long tareas = (n + 6) / 7;
        int cnt = min(tareas / 2, (p + l + 2*a - 1) / (l + 2*a));
        //cout << "Dobles: " << cnt << '\n';
        p -= cnt * (l + 2*a);
        p = max(p, 0ll);
        tareas -= cnt * 2;

        int d_tl = min(tareas, (p + l + a - 1) / (l + a));
        cnt += d_tl;
        p -= d_tl * (l + a);
        p = max(p, 0ll);
        tareas -= d_tl;

        int d_l = min(n - cnt, (p + l - 1) / l);
        cnt += d_l;
        p -= d_l * l;
        p = max(p, 0ll);
        //cout << "P: " << p << "\nTareas: " << tareas << '\n';

        cout << n - cnt << '\n';
    }
}
