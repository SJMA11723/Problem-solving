#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    cout << s.substr(0, (int)s.size() - 1) << "ic" << s.back() << '\n';
}
