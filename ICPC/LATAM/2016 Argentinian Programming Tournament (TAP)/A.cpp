#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    bool ok = true;
    for(char c : s) ok = ok && c != 'i';
    cout << (ok ? "S\n" : "N\n");
}
