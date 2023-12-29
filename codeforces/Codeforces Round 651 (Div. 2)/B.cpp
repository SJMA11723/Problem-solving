/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_power_of_two(S) (!((S) & ((S) - 1)))

using namespace std;

bool is_prime(int n){
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n > 1 && (n % 2 || n == 2 || (!is_power_of_two(n) && n % 4 == 0) || (n % 4 && !is_prime(n / 2)))) cout << "Ashishgup\n";
        else cout << "FastestFinger\n";
    }
}

