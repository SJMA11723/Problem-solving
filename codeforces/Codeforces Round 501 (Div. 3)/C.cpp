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
    int64_t sum = 0;
    int a[n];
    for(int &x : a){
        cin >> x;
        int y; cin >> y;
        sum += x;
        x -= y;
    }
    sort(a, a + n, greater<int>());

    int ans = 0;
    while(sum > m && ans < n) sum -= a[ans++];

    cout << (sum <= m ? ans : -1) << '\n';
}
