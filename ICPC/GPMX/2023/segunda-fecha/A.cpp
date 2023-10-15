#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ofstream out("out.txt");

    int k;
    string n;
    cin >> k >> n;

    int ans = 0;
    for(int i = 0; i < n.size(); ++i){
        int c = n[i] - '0';
        if(c != 0 && c != 6 && c != 8) ans++;
    }
    cout << ans << '\n';

    /*cout << "\n";
    for(int i = 1; i < 10000000; ++i){
        int c = i;
        bool ok = true;
        while(c){
            int d = c % 10;
            if(c != 0 || c != 6 || c != 8) ok = false;
            c /= 10;
        }
        if(ok && i % 64 == 0 && (i % 100 == 68 || i % 100 == 88 || i % 100 == 8)) out << i << '\n';
    }*/
    return 0;
}
