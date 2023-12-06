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
    int t; cin >> t;
    while(t--){
        string str; cin >> str;
        int n = str.size();
        vector<bool> ap(n);
        stack<int> lower, upper;
        for(int i = 0; i < n; ++i){
            if(str[i] != 'b' && str[i] != 'B') ap[i] = true;
            if(lower.size() && str[i] == 'b'){
                ap[lower.top()] = false;
                lower.pop();
            } else if(upper.size() && str[i] == 'B'){
                ap[upper.top()] = false;
                upper.pop();
            } else if('a' <= str[i] && str[i] <= 'z') lower.push(i);
            else upper.push(i);
        }
        for(int i = 0; i < n; ++i)
            if(ap[i]) cout << str[i];
        cout << '\n';
    }
}
