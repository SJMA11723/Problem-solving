/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
* LinkedIn: https://www.linkedin.com/in/jorgetzab/
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
        int arr[n];
        long long unos = 0, ans = 0;
        int pos1 = -1, pos0 = -1;

        for(int i = 0; i < n; ++i){
            cin >> arr[i];

            if(arr[i]) unos++;
            else ans += unos;

            if(pos0 == -1 && !arr[i]) pos0 = i;
            if(arr[i]) pos1 = i;
        }

        unos = 0;
        long long unos0 = 0, inv = 0, inv0 = 0;
        for(int i = 0; i < n; ++i){
            if(arr[i]){
                if(i == pos1) inv += unos;
                else unos++;
                unos0++;
            } else {
                if(i == pos0) unos0++;
                else inv0 += unos0;
                inv += unos;
            }
        }

        cout << max({ans, inv, inv0}) << '\n';
    }
}
