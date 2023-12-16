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
    string n; cin >> n;
    if(n == "0"){
        cout << "4\n";
        return 0;
    }
    int mod4 = (n.back() - '0') % 4;
    n.pop_back();
    if(n.size()) mod4 = (mod4 + 10 * (n.back() - '0')) % 4;

    int ciclo2[4] = {1, 2, 4, 3};
    int ciclo3[4] = {1, 3, 4, 2};
    cout << (1 + ciclo2[mod4] + ciclo3[mod4] + ciclo2[mod4 % 2 * 2]) % 5 << '\n';
}
