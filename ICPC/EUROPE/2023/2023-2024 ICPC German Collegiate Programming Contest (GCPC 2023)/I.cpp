#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1 << (i)))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set<int> free_pos;
    for(int i = 1; i <= 1300000; ++i) free_pos.insert(i);

    int n; cin >> n;
    int arr[n];
    for(int &x : arr){
        cin >> x;
        free_pos.erase(x);
    }

    int q; cin >> q;
    while(q--){
        int i; cin >> i; i--;
        int pos = *free_pos.upper_bound(arr[i]);
        cout << pos << '\n';
        free_pos.insert(arr[i]);
        free_pos.erase(pos);
        arr[i] = pos;
    }
}
