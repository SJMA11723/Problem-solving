/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long arr[n + 1];
        arr[0] = 0;
        for(int i = 1; i <= n; ++i){
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }

        int ini = 1, fin = n;
        while(ini < fin){
            int mitad = (ini + fin) / 2;

            cout << "? " << mitad - ini + 1 << ' ';
            for(int i = ini; i <= mitad; ++i) cout << i << ' ';
            cout << '\n'; cout.flush();

            long long x; cin >> x;

            if(arr[mitad] - arr[ini - 1] < x) fin = mitad;
            else ini = mitad + 1;
        }
        cout << "! " << ini << '\n';
    }
}
