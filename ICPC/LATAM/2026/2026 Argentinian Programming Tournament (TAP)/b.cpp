#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

bool vocal(char c){
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    set<string> mset;
    for(int i = 4; i < n; ++i){
        if(vocal(s[i]) && s[i] == s[i - 4] && s[i - 3] == 'G' && s[i - 2] == 'A' && s[i - 1] == 'S'){
            string newstr = s;
            newstr.erase(newstr.begin() + i - 4, newstr.begin() + i);
            mset.insert(newstr);
        }
    }

    if(mset.size() == 1) cout << *mset.begin() << '\n';
    else if(mset.size() == 0) cout << "-\n";
    else cout << "+\n";
}