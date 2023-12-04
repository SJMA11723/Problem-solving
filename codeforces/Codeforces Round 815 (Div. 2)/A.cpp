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
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        if(!a) cout << (bool)(c) << '\n';
        else if(!c) cout << (bool)(a) << '\n';
        else if(b * c == a * d) cout << "0\n";
        else if((b * c) % (a * d) == 0 || (a * d) % (b * c) == 0) cout << "1\n";
        else cout << "2\n";
    }
}
