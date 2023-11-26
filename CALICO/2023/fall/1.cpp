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
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        if(n == 0) cout << "haha good one\n";
        else if(n == 10) cout << "berkeleytime\n";
        else if(n == 20) cout << "berkeleyberkeleytime\n";
        else if(n == 30) cout << "berkeleyberkeleyberkeleytime\n";
        else if(n <= 170) {
            for(int i = 0; i < n / 10; ++i) cout << "berkeley";
            cout << "time\n";
        } else cout << "canceled\n";
    }
}
