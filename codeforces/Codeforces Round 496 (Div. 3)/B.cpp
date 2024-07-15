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
    string s, t; cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    int ptr = 0;
    while(ptr < min(s.size(), t.size()) && s[ptr] == t[ptr]) ptr++;
    cout << s.size() + t.size() - 2*ptr << '\n';
}
