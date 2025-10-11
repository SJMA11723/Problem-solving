#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c, d; cin >> a >> b >> c >> d;
    int c1, c2;
    if(a > 0){
        if(b > 0) c1 = 1;
        else c1 = 4;
    } else {
        if(b > 0) c1 = 2;
        else c1 = 3;
    }

    if(c > 0){
        if(d > 0) c2 = 1;
        else c2 = 4;
    } else {
        if(d > 0) c2 = 2;
        else c2 = 3;
    }

    cout << (c1 != c2) << '\n';

}
