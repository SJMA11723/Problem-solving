/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool square(int x, int o, int l){
    int rx = sqrt(x), ro = sqrt(o);
    return x + o == l*l && ((rx * rx == x && 4 * l  - 4 == o) || (ro * ro == o && 4 * l - 4 == x));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string str;
    cin >> str;

    long long ans = 0;

    for(int l = 3; l * l <= n; ++l){
        int x = 0, o = 0;
        int tam = l * l;
        for(int i = 0; i < tam; ++i){
            if(str[i] == 'X') x++;
            else o++;
        }

        if(square(x, o, l)) ans++;

        for(int i = tam; i < n; ++i){
            if(str[i] == 'X') x++;
            else o++;

            if(str[i - tam] == 'X') x--;
            else o--;

            if(square(x, o, l)) ans++;
        }
    }

    cout << ans << '\n';
}
