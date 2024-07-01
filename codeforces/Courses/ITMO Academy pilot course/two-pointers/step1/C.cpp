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
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    int64_t ans = 0;
    int ptr_b = 0, next_b;
    for(int i = 0; i < n; ++i){
        bool ok = false;
        while(ptr_b < m && b[ptr_b] < a[i]) ptr_b++, ok = true;
        if(ok) next_b = ptr_b;
        while(next_b < m && b[ptr_b] == b[next_b]) next_b++;

        ans += (next_b - ptr_b) * (a[i] == b[ptr_b]);
    }

    cout << ans << '\n';
}
