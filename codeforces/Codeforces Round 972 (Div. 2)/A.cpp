/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

using namespace std;

const char vowels[6] = "aeiou";

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n == 1) cout << "a\n";
        else if(n == 2) cout << "ae\n";
        else if(n == 3) cout << "aei\n";
        else if(n == 4) cout << "aeio\n";
        else cout << string(n / 5 + (n % 5 > 0), 'a') +
                     string(n / 5 + (n % 5 - 1 > 0), 'e') +
                     string(n / 5 + (n % 5 - 2 > 0), 'i') +
                     string(n / 5 + (n % 5 - 3 > 0), 'o') +
                     string(n / 5, 'u') << '\n';
    }
}
