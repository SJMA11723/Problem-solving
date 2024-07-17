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
    string a, b; cin >> a >> b;

    int ans = (n % 2 && a[n / 2] != b[n / 2]);
    for(int i = 0; i < n / 2; ++i){
        int add = 2;
        if(a[i] == b[i]) add = min(add, int(a[n - 1 - i] != b[n - 1 - i]));
        if(a[i] == b[n - 1 - i]) add = min(add, int(a[n - 1 - i] != b[i]));

        if(a[n - 1 - i] == b[i]) add = min(add, int(a[i] != b[n - 1 - i]));
        if(a[n - 1 - i] == b[n - 1 - i]) add = min(add, int(a[i] != b[i]));

        if(b[i] == b[n - 1 - i]) add = min(add, int(a[n - 1 - i] != a[i]));

        ans += add;
    }

    cout << ans << '\n';
}
