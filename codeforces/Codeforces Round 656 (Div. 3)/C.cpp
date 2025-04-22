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
        int arr[n];
        for(int &x : arr) cin >> x;
        int lenR = 1;
        for(int i = n - 2; 0 <= i; --i){
            if(arr[i] >= arr[i + 1]) lenR++;
            else break;
        }

        int lenL = 0;
        for(int i = n - lenR - 1; 0 <= i; --i){
            lenL++;
            if(i && arr[i - 1] > arr[i]) break;
        }

        cout << n - min(n, lenR + lenL) << '\n';
    }
}
