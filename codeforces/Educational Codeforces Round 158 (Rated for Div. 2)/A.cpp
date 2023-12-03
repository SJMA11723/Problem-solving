/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool check(int cap, int arr[], int n, int x){
    int tank = cap;
    for(int i = 0; i < n; ++i){
        tank -= arr[i] - (0 <= i - 1 ? arr[i - 1] : 0);
        if(tank < 0) return false;
        tank = cap;
    }
    tank -= x - arr[n - 1];
    if(tank < 0) return false;

    for(int i = n - 1; 0 <= i; --i){
        tank -= (i + 1 < n ? arr[i + 1] : x) - arr[i];
        if(tank < 0) return false;
        tank = cap;
    }
    tank -= arr[0];
    if(tank < 0) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int arr[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }

        int ini = 0, fin = 2 * x;
        while(ini < fin){
            int mitad = (ini + fin) / 2;
            if(check(mitad, arr, n, x)) fin = mitad;
            else ini = mitad + 1;
        }
        cout << ini << '\n';
    }
}
