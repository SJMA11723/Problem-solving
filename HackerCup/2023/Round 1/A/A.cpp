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
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int t;
    cin >> t;

    for(int tt = 1; tt <= t; ++tt){
        int n; cin >> n;
        long double elf[n];
        for(int i = 0; i < n; ++i) cin >> elf[i];
        sort(elf, elf + n);

        cout << "Case #" << tt << ": ";
        cout << fixed << setprecision(6);
        if(n == 5){
            cout << max((elf[4] + elf[2] - elf[0] - elf[1]) / 2, (elf[4] + elf[3] - elf[0] - elf[2]) / 2) << '\n';
        } else {
            cout << (elf[n - 1] + elf[n - 2] - elf[0] - elf[1]) / 2 << '\n';
        }
    }

}
