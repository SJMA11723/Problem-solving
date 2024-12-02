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
    int fact[11];
    fact[0] = 1;
    for(int i = 1; i < 11; ++i) fact[i] = i * fact[i - 1];

    string s1, s2;
    cin >> s1 >> s2;
    int sum1 = 0, sum2 = 0;
    for(char c : s1){
        if(c == '+') sum1++;
        else sum1--;
    }

    int cnt = 0;
    for(char c : s2){
        if(c == '+') sum2++;
        else if(c == '-') sum2--;
        else cnt++;
    }

    int r = sum1 - sum2;

    if((r + cnt) % 2){
        cout << "0\n";
        return 0;
    }

    int a = (r + cnt) / 2;
    int b = cnt - a;

    if(a < 0 || b < 0){
        cout << "0\n";
        return 0;
    }

    cout << fixed << setprecision(10) << (long double)(fact[cnt] / fact[a] / fact[cnt - a]) / (1 << cnt) << '\n';
}
