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
    for(int i = 0; i < n; ++i){
        if(i % 2) cout << "I love ";
        else cout << "I hate ";
        if(i + 1 < n) cout << "that ";
        else cout << "it\n";
    }
}
