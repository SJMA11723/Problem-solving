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
    int maxi1 = 0;
    while(n--){
        int x; cin >> x;
        maxi1 = max(maxi1, x);
    }

    cin >> n;
    int maxi2 = 0;
    while(n--){
        int x; cin >> x;
        maxi2 = max(maxi2, x);
    }

    cout << maxi1 << ' ' << maxi2 << '\n';
}
