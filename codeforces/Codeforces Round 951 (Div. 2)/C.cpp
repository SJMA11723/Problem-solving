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
        int l = 1;
        int arr[n];
        for(int &x : arr){
            cin >> x;
            l = lcm(l, x);
        }

        int sum = 0;
        for(int i = 0; i < n; ++i) sum += l / arr[i];
        if(sum >= l) cout << "-1\n";
        else for(int i = 0; i < n; ++i) cout << l / arr[i] << " \n"[i + 1 == n];
    }
}
