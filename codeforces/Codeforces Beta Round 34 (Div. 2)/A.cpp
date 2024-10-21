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
    int a = 1, b = 2;
    int arr[n]; cin >> arr[0];
    for(int i = 1; i < n; ++i){
        cin >> arr[i];
        if(abs(arr[i] - arr[i - 1]) < abs(arr[a - 1] - arr[b - 1]))
            a = i + 1, b = i;
    }
    if(abs(arr[n - 1] - arr[0]) < abs(arr[a - 1] - arr[b - 1]))
        a = n, b = 1;
    cout << a << ' ' << b << '\n';
}
