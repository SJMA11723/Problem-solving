/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        if(x % 2) cnt1++;
        else cnt2++;
    }

    int sum = 0;
    for(int i = 0; i < n; ++i){
        if(!cnt2 || (cnt1 && is_prime(sum + 1))) sum++, cnt1--, cout << "1 ";
        else sum += 2, cnt2--, cout << "2 ";
    }
    cout << '\n';
}
