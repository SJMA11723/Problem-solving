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
    string n, m; cin >> n >> m;
    if(n == m){
        cout << "1\n";
        return 0;
    }

    map<string, int> idx;
    idx[n] = 1;

    for(int i = 2; i <= 100; ++i){
        int cub[10] = {};
        for(char c : n)
            cub[c - '0']++;
        n = "";
        for(int i = 0; i < 10; ++i){
            if(cub[i]){
                n += to_string(cub[i]);
                n += to_string(i);
            }
        }

        if(n == m){
            cout << i << '\n';
            return 0;
        }

        if(idx.count(n)){
            cout << "Does not appear\n";
            return 0;
        }

        idx[n] = i;
    }

    cout << "I'm bored\n";
}
