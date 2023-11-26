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
        int p;
        string str;
        cout << "feed 50" << endl;
        cin >> str;
        cout << "feed 100" << endl;
        cin >> str;
        cout << "feed 25" << endl;
        cin >> str;
        cout << "poop" << endl;
        cin >> p;
        cout << "guess ";
        if(p == 100) cout << "heapeon";
        else if(p == 25) cout << "stackeon";
        else cout << "queueon";
        cout << endl;
        cin >> str;
        if(str == "WRONG_ANSWER")
            exit(0);
    }
}
