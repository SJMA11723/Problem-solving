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
    int dado_1[n], dado_2[n];
    for(int i = 0; i < n; ++i)
        cin >> dado_1[i];

    for(int i = 0; i < n; ++i)
        cin >> dado_2[i];

    int gana_1 = 0, gana_2 = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(dado_1[i] < dado_2[j]) gana_2++;
            else if(dado_1[i] > dado_2[j]) gana_1++;
        }
    }

    if(gana_1 > gana_2) cout << "first\n";
    else if(gana_1 < gana_2) cout << "second\n";
    else cout << "tie\n";
}
