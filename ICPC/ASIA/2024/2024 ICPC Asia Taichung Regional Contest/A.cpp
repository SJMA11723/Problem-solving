#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set<int> ap;
    ap.insert(1);
    ap.insert(2);
    ap.insert(3);
    ap.insert(4);
    ap.insert(5);

    for(int i = 0; i < 4; ++i){
        int x; cin >> x;
        ap.erase(x);
    }

    cout << *ap.begin() << '\n';
}
