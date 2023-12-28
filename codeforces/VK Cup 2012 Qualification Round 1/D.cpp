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
    int arr[n], ans = 0;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        ans += arr[i];
    }

    int sum;
    for(int d = 2; d < n; ++d){
        if(n % d != 0 || n / d < 3) continue;
        for(int i = 0; i < d; ++i){
            sum = 0;
            for(int j = i; j < n; j += d) sum += arr[j];
            ans = max(ans, sum);
        }
    }
    cout << ans << '\n';
}
