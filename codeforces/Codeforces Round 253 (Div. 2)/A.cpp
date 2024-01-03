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
    set<char> mset;
    char c;
    do{
        cin >> c;
        if(isalpha(c)) mset.insert(c);
    }while(c != '}');
    cout << mset.size() << '\n';
}
