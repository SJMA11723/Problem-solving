#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int B, L; cin >> B >> L;
    vector<int> N(L);
    for(int &d : N) cin >> d;

    int r = 0, powB = 1, cnt1 = 0;
    for(int i = L - 1; 0 <= i; --i){
        int d = N[i];
        r += d * powB % (B + 1);
        if(r >= B + 1) r -= B + 1;
        powB = powB * B % (B + 1);
    }

    if(!r){
        cout << "0 0\n";
        return 0;
    }

    int idx = -1, d = -1;
    if(L % 2 == 0) r = -r;
    for(int i = 0; i < L; ++i){
        int x = (r + B + 1) % (B + 1);
        if(x <= N[i]){
            idx = i + 1;
            d = N[i] - x;
            break;
        }

        r = -r;
    }

    cout << idx << ' ' << d << '\n';
}
