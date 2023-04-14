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
        long long c;
        int n; cin >> n >> c;
        pair<long long, long long> arr[n];
        long long acc[n + 1] = {};
        for(int i = 0; i < n; ++i){
            cin >> arr[i].first;
            arr[i].second = arr[i].first + i + 1;
            arr[i].first += min(n - i, i + 1);
        }
        sort(arr, arr + n);
        /// acc[i] es el acumulado hasta los primeros i - 1 (minimos, first)
        for(int i = 1; i <= n; ++i) acc[i] = arr[i - 1].first + acc[i - 1];

        int ans = 0;
        for(int i = 0; i < n; ++i){
            int ini = 0, fin = n, act = 0;
            while(ini <= fin){
                int mitad = (ini + fin) / 2;
                long long costo = acc[mitad] + arr[i].second;
                if(i < mitad) costo -= arr[i].first;

                if(costo <= c){
                    act = max(act, mitad + (mitad < i));
                    ini = mitad + 1;
                } else fin = mitad - 1;
            }
            ans = max(ans, act);
        }

        cout << ans << '\n';
    }
}
