#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    string str;
    while(t--){
        getline(cin, str);
        int n, m;
        cin >> n >> m;
        pair<long long, pair<long long, int>> arr[m];
        for(int i = 0; i < m; ++i){
            long long a, b;
            cin >> a >> b;
            arr[i] = {b, {a, i + 1}};
        }

        sort(arr, arr + m);

        long long sum = 0;

        for(int i = 0; i < 2 * n; ++i){
            sum += arr[i].first;
            swap(arr[i].first, arr[i].second.first);
        }

        sort(arr, arr + 2 * n);

        cout << sum << '\n';
        for(int i = 0; i < (2 * n) / 2; ++i){
            cout << arr[i].second.second << ' ' << arr[2 * n - 1 - i].second.second << '\n';
        } cout << '\n';
    }
}
