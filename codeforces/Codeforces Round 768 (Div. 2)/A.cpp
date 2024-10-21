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
        int a[n], b[n];
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;

        for(int i = 0; i < n; ++i)
            if(a[i] > b[i]) swap(a[i], b[i]);

        cout << *max_element(a, a + n) * *max_element(b, b + n) << '\n';
    }
}
