#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int sum = 0;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        sum += x;
    }
    for(int i = n; 0 < i; --i){
        if(sum % i) continue;
        cout << n - i << '\n';
        return 0;
    }
    return 0;
}