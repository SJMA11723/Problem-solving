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
        int arr[3];
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr + 3);
        arr[0]++;
        if(arr[2] > arr[0]) arr[2]--;
        else if(arr[2] < arr[0]) arr[2]++;
        if(arr[1] < arr[0]) arr[1]++;
        else if(arr[1] > arr[2]) arr[1]--;

        cout << 1ll * abs(arr[0] - arr[1]) + abs(arr[0] - arr[2]) + abs(arr[1] - arr[2]) << '\n';
    }
}
