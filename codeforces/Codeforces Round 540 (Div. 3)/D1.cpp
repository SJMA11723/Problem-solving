/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool check(int n, int caffeine[], int days, int m){
    int sum = 0;
    for(int i = 0; i < n; ++i) sum += max(0, caffeine[i] - i / days);
    return sum >= m;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int caffeine[n];
    for(int &x : caffeine) cin >> x;
    sort(caffeine, caffeine + n, greater<int>());
    int l = 1, r = n + 1;
    while(l < r){
        int mid = l + (r - l) / 2;
        if(check(n, caffeine, mid, m)) r = mid;
        else l = mid + 1;
    }
    cout << (l == n + 1 ? -1 : l) << '\n';
}
