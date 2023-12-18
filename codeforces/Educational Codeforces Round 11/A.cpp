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
    int arr[n]; cin >> arr[0];
    int cnt = 0;
    for(int i = 1; i < n; ++i){
        cin >> arr[i];
        if(gcd(arr[i], arr[i - 1]) != 1) cnt++;
    }

    cout << cnt << '\n' << arr[0] << ' ';
    for(int i = 1; i < n; ++i){
        if(gcd(arr[i], arr[i - 1]) != 1) cout << "1 ";
        cout << arr[i] << ' ';
    }
    cout << '\n';
}
