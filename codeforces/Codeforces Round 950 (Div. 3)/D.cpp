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
        int arr[n]; arr[n] = 0;
        for(int i = 0; i < n; ++i) cin >> arr[i];

        bool ok = false;

        int prv = INT_MIN;
        int a = -1, b = -1, c = -1;
        for(int i = 1; i < n; ++i){
            int g = __gcd(arr[i], arr[i - 1]);
            if(prv <= g) prv = g;
            else {
                c = i - 2;
                a = i - 1;
                b = i;
                break;
            }
            //cout << prv << ' ';
        } //cout << '\n';

        //cout << a << ' ' << b << '\n';
        if(a != -1){
            prv = INT_MIN;
            bool nondec = true;
            for(int i = 1; i < n; ++i){
                if(i == a) continue;
                int g = __gcd(arr[i], i - 1 == a ? arr[i - 2] : arr[i - 1]);
                if(prv <= g) prv = g;
                else {
                    nondec = false;
                    break;
                }
            }
            ok |= nondec;

            prv = INT_MIN;
            nondec = true;
            for(int i = 1; i < n; ++i){
                if(i == b) continue;
                int g = __gcd(arr[i], i - 1 == b ? arr[i - 2] : arr[i - 1]);
                if(prv <= g) prv = g;
                else {
                    nondec = false;
                    break;
                }
            }
            ok |= nondec;


            prv = INT_MIN;
            nondec = true;
            for(int i = (c ? 1 : 2); i < n; ++i){
                if(i == c) continue;
                int g = __gcd(arr[i], i - 1 == c ? arr[i - 2] : arr[i - 1]);
                if(prv <= g) prv = g;
                else {
                    nondec = false;
                    break;
                }
            }
            ok |= nondec;
        } else ok = true;

        if(ok) cout << "YES\n";
        else  cout << "NO\n";
    }
}
