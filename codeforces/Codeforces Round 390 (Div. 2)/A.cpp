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
    int first_nonzero = -1, sum = 0;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        sum += x;
        if(x && first_nonzero == -1) first_nonzero = i + 1;
    }
    if(sum) cout << "YES\n1\n1 " << n << '\n';
    else if(first_nonzero != -1) cout << "YES\n2\n1 " << first_nonzero << '\n' << first_nonzero + 1 << ' ' << n << '\n';
    else cout << "NO\n";
}
