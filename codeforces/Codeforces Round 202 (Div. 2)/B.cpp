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
    int v; cin >> v;
    int maxi = 0, digit;
    int a[10];
    for(int i = 1; i <= 9; ++i){
        int x; cin >> x;
        a[i] = x;
        if(maxi <= v / x){
            maxi = v / x;
            digit = i;
        }
    }

    if(!maxi){
        cout << "-1\n";
        return 0;
    }

    int mini = *min_element(a + 1, a + 10);
    for(int i = 0; i < maxi; ++i){
        for(int d = 9; 1 <= d; --d){
            if(a[d] <= v && (v - a[d]) / mini >= maxi - i - 1){
                cout << d;
                v -= a[d];
                break;
            }
        }
    }
    cout << '\n';
}
