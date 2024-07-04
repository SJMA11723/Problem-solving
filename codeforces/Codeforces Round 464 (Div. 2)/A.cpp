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
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        arr[i]--;
    }

    bool ok = false;
    for(int i = 0; i < n; ++i)
        if(arr[i] != i && arr[arr[i]] != i && arr[arr[arr[i]]] == i) ok = true;
    cout << (ok ? "YES\n" : "NO\n");
}
