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
    long long n; cin >> n;
    int ans = 0;
    while(n && n % 2){
        long long div = -1;
        for(long long i = 2; i * i <= n; ++i){
            if(n % i == 0){
                div = i;
                break;
            }
        }
        if(div == -1) div = n;
        n -= div;
        ans++;
    }
    cout << ans + n / 2<< '\n';
}
