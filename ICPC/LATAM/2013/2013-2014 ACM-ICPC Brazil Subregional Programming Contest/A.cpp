#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c; cin >> a >> b >> c;
    if(a != b && a != c){
        cout << "A\n";
        return 0;
    }

    if(a != b && b != c){
        cout << "B\n";
        return 0;
    }

    if(c != b && a != c){
        cout << "C\n";
        return 0;
    }

    cout << "*\n";
}
