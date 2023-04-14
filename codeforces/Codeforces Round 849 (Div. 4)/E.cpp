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
        long long arr[n], suma = 0;
        bool negative = false;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            suma += abs(arr[i]);
            if(arr[i] < 0) negative = !negative;
        }

        if(negative){
            long long mini = 1e10;
            for(int i = 0; i < n; ++i) mini = min(mini, abs(arr[i]));
            suma -= 2*mini;
        }

        cout << suma << '\n';
    }
}
