#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << "1 1\n";
        cout.flush();

        int res; cin >> res;

        cout << "1 11\n";
        cout.flush();

        int res1; cin >> res1;

        cout << "1 10\n";
        cout.flush();

        int res2; cin >> res2;

        cout << "0 " << n;
        cout.flush();
        if(res == res1 + res2) cout << " 0\n";
        else cout << " 1\n";
        cout.flush();

        cin >> res;
    }
}
