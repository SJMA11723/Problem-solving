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
        int n; cin >> n;
        if(n <= 4){
            cout << "-1\n";
            continue;
        }

        int max_odd = n;
        if(n % 2 == 0) max_odd--;

        cout << "2 ";
        for(int i = 6; i <= n; i += 2) cout << i << ' ';
        cout << "4 5 1 3" << " \n"[n == 5];
        for(int i = 7; i <= n; i += 2) cout << i << " \n"[i == max_odd];
    }
}

