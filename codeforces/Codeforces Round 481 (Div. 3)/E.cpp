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
    int n, w; cin >> n >> w;
    int sum = 0;
    int maxi = INT_MIN, mini = INT_MAX;
    while(n--){
        int x; cin >> x;
        sum += x;
        maxi = max(maxi, sum);
        mini = min(mini, sum);
    }

    if(abs(maxi) > w || abs(mini) > w) cout << "0\n";
    else cout << max(0, (w - max(0, maxi)) - max(0, -mini) + 1) << '\n';
}
