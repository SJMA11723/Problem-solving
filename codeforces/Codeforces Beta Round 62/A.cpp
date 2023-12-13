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
    int p1, p2, p3, p4, a, b;
    cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
    int mini = min({p1, p2, p3, p4});
    if(a < mini) cout << min(b + 1, mini) - a << '\n';
    else cout << "0\n";
}
