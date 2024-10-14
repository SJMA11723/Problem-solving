#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string num; cin >> num;
    set<char> mset;
    for(char c : num) if(c != '-') mset.insert(c);
    cout << mset.size() << '\n';
}
