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
        int arr[n + 1];
        for(int i = 1; i <= n; ++i) cin >> arr[i];
        sort(arr + 1, arr + n + 1);
        int median = arr[(n + 1) / 2], cnt = 0;
        for(int i = (n + 1) / 2; i <= n; ++i) if(arr[i] == median) cnt++;
        cout << cnt << '\n';
    }
}
