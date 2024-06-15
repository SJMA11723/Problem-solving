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
    int n;
    while(cin >> n){
        int64_t squares = 0, rectangles = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(i == j) squares += (n - i + 1) * (n - j + 1);
                rectangles += (n - i + 1) * (n - j + 1);
            }
        }
        cout << squares << ' ' << rectangles << '\n';
    }
}
