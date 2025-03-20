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
        int even = 0, odd = 0;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(x % 2 != i % 2){
                if(i % 2) odd++;
                else even++;
            }
        }

        if(odd != even){
            cout << "-1\n";
            continue;
        }

        cout << odd << '\n';
    }
}
