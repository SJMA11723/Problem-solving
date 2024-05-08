#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int O, A, K;
    cin >> O >> A >> K;
    for(int a = 1; a <= 150; ++a){
        for(int k = 1; k <= 150; ++k){
            if(O == a * A + k * K){
                cout << "1\n";
                return 0;
            }
        }
    }
    cout << "0\n";
}
