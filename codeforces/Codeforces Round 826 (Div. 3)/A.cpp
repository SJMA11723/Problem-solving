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
        string a, b;
        cin >> a >> b;
        if(a.back() == b.back()){
            if(a.back() == 'M'){
                cout << "=\n";
                continue;
            }

            int cnt1 = 0, cnt2 = 0;
            for(char c : a) if(c == 'X') cnt1++;
            for(char c : b) if(c == 'X') cnt2++;

            if(a.back() == 'S'){
                if(cnt1 < cnt2) cout << ">\n";
                else if(cnt1 > cnt2) cout << "<\n";
                else cout << "=\n";
            } else {
                if(cnt1 < cnt2) cout << "<\n";
                else if(cnt1 > cnt2) cout << ">\n";
                else cout << "=\n";
            }

        } else if(a.back() == 'S') cout << "<\n";
        else if(a.back() == 'L') cout << ">\n";
        else if(b.back() == 'S') cout << ">\n";
        else cout << "<\n";
    }
}
