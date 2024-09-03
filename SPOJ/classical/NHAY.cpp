/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
void preffix_funtion(string &s, vector<int> &pi){
    pi[0] = 0;
    for(int i = 1; i < s.size(); ++i){
        int j = pi[i - 1];
        while(0 < j && s[i] != s[j]) j = pi[j - 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin >> n){
        string s, t; cin >> s >> t;
        string pre = s + "#" + t;
        vector<int> pi(pre.size());
        preffix_funtion(pre, pi);
        for(int i = 0; i < pi.size(); ++i) if(pi[i] == s.size()) cout << i - 2 * (int)s.size() << '\n';
        cout << '\n';
    }
}
 