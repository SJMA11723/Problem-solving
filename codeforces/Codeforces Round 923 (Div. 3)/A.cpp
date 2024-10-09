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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int first = -1, last = -1;
        for(int i = 0; i < n; ++i){
            char c; cin >> c;
            if(c == 'B'){
                if(first == -1) first = i;
                last = i;
            }
        }
        cout << last - first + 1 << '\n';
    }
}
