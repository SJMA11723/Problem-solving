/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int x;
        pair<bool, int> unico[n + 1];
        bool aparece[n + 1];

        fill(aparece, aparece + n + 1, 0);

        for(int i = 1; i <= n; ++i) unico[i] = {1, 0};

        for(int i = 1; i <= n; ++i){
            cin >> x;
            if(aparece[x])unico[x].first = false;
            aparece[x] = 1;
            unico[x].second = i;
        }

        for(int i = 1; i <= n; ++i){
            if(unico[i].first && aparece[i]){
                cout << unico[i].second << '\n';
                break;
            } else if(i == n) cout << "-1\n";
        }
    }
}
