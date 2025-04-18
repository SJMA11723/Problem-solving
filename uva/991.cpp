/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 10

using namespace std;

int C[MAXN + 1];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    C[0] = 1;
    for(int i = 1; i <= MAXN; ++i)
    for(int j = 0; j < i; ++j) C[i] += C[j] * C[i - 1 - j];

    bool first = true;
    int n;
    while(cin >> n){
        if(first) first = false;
        else cout << '\n';
        cout << C[n] << '\n';
    }
}
