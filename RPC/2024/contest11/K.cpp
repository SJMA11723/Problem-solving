#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int64_t n,p; cin >> n >>p;

    if( n%2==0 ){
        if(  (n-p)%(p*2) == p  ){
            cout << 0 << '\n';
            return 0;
        }
        cout << (n-p)%(p*2) << '\n';
        return 0;
    }
    cout << (n-p)%(p*2) << '\n';
}
