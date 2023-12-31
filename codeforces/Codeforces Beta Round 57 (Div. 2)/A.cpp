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
    string A, B;
    cin >> A >> B;
    for(int i = 0; i < A.size(); ++i) cout << ((A[i] - '0') ^ (B[i] - '0'));
    cout << '\n';
}
