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

    int ptr_b = 0, ans = -1;
    for(int i = 0; i < n; ++i){
        while(ptr_b + 1 < m && b[ptr_b + 1] <= a[i]) ptr_b++;
        ans = max(ans, min(abs(a[i] - b[ptr_b]), (ptr_b + 1 == m ? INT_MAX : abs(a[i] - b[ptr_b + 1]))));;
    }
    cout << ans << '\n';
}
