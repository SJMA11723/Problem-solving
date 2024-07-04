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
    for(int &x : arr) cin >> x;

    if(is_sorted(arr, arr + n)){
        cout << "yes\n1 1\n";
        return 0;
    }

    bool ok = true;
    int l = -1, r = -1;
    for(int i = 0; i + 1 < n; ++i){
        if(arr[i] > arr[i + 1]){
            if(ok) l = i;
            ok = false;
        } else if(arr[i] < arr[i + 1]){
            if(!ok){
                r = i;
                break;
            }
            ok = true;
        }
    }
    if(l == -1) l = 0;
    if(r == -1) r = n - 1;
    reverse(arr + l, arr + r + 1);

    if(is_sorted(arr, arr + n)) cout << "yes\n" << l + 1 << ' ' << r + 1 << '\n';
    else cout << "no\n";
}
