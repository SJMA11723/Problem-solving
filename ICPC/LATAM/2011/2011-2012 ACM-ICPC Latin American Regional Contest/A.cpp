#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int S, B; cin >> S >> B;
    while(S && B){
        set<int> soldiers;
        for(int i = 1; i <= S; ++i) soldiers.insert(i);

        while(B--){
            int l, r; cin >> l >> r;
            for(int i = l; i <= r; ++i) soldiers.erase(i);

            auto it = soldiers.lower_bound(l);
            if(it != soldiers.begin()){
                --it;
                cout << *it << ' ';
            } else cout << "* ";

            it = soldiers.upper_bound(r);
            if(it != soldiers.end()) cout << *it << '\n';
            else cout << "*\n";
        }
        cout << "-\n";
        cin >> S >> B;
    }
}
