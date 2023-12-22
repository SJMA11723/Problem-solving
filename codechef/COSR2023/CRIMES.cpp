/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool check(long long x[], int n, int k, const long long D){
    if(x[n - 1] - x[0] <= D) return true;
    int last_e = -1, first_not_covered = 0;
    for(int i = 0; i < n && k; ++i){
        if(x[i] - x[first_not_covered] > D){
            last_e = i - 1;
            k--;
            first_not_covered = i;
            while(first_not_covered < n && x[first_not_covered] - x[last_e] <= D) first_not_covered++;
            i = first_not_covered - 1;
        }
    }

    return x[n - 1] - x[last_e] <= D || k;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        long long x[n];
        for(int i = 0; i < n; ++i) cin >> x[i];
        sort(x, x + n);
        if(n == 1){
            cout << "0\n";
            continue;
        }

        long long ini = 0, fin = LLONG_MAX;
        while(ini < fin){
            long long mitad = (ini + fin) / 2;
            if(check(x, n, k, mitad)) fin = mitad;
            else ini = mitad + 1;
        }
        cout << ini << '\n';
    }
}
