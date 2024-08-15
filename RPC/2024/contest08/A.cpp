#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    for(char &c : s) if('A' <= c && c <= 'Z') c += 'a' - 'A';

    if(is_sorted(s.begin(), s.end())){
        cout << "yes\n";
        return 0;
    }

    reverse(s.begin(), s.end());

    if(is_sorted(s.begin(), s.end())){
        cout << "yes\n";
        return 0;
    }

    cout << "no\n";
}
