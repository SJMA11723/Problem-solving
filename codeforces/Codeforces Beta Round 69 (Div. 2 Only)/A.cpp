/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x){
    if(x < 2) return false;
    for(int i = 2; i * i <= x; ++i)
        if(x % i == 0) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int next = n + 1;
    while(!is_prime(next)) next++;
    cout << (next == m ? "YES\n" : "NO\n");
}
