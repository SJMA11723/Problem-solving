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
    set<char> codeforces;
    codeforces.insert('c');
    codeforces.insert('o');
    codeforces.insert('d');
    codeforces.insert('e');
    codeforces.insert('f');
    codeforces.insert('o');
    codeforces.insert('r');
    codeforces.insert('c');
    codeforces.insert('e');
    codeforces.insert('s');
    int t; cin >> t;
    while(t--){
        char c; cin >> c;
        if(codeforces.count(c)) cout << "yes\n";
        else cout << "no\n";
    }
}
