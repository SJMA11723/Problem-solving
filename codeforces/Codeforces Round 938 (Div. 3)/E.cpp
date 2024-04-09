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
        int n; cin >> n;
        string str; cin >> str;
        for(int k = n; 0 < k; --k){
            int unos = 0;
            bool cambio[n + 1] = {}, flip = false;
            for(int i = 0; i < n; ++i){
                if(cambio[i]) flip = !flip;

                if(!flip){
                    if(str[i] == '1'){
                        unos++;
                        continue;
                    }

                    if(i + k - 1 < n){
                        flip = !flip;
                        cambio[i + k] = true;
                        unos++;
                    }
                } else {
                    if(str[i] == '0'){
                        unos++;
                        continue;
                    }

                    if(i + k - 1 < n){
                        flip = !flip;
                        cambio[i + k] = true;
                        unos++;
                    }
                }
            }

            if(unos == n){
                cout << k << '\n';
                break;
            }
        }
    }
}
