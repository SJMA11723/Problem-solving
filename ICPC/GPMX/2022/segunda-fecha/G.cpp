#include <bits/stdc++.h>

using namespace std;

int n;
long long arr[2000005];
int idx;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    idx = 2;
    for(int i = 0; i < n - 1; ++i){
        cin >> arr[idx];
        idx += 2;
    }

    idx = 1;
    for(int i = 0; i < n; ++i){
        cin >> arr[idx];
        idx += 2;
    }

    arr[0] = 0;
    int tam = 2 * n - 1;
    for(int i = 1; i <= tam; ++i){
        arr[i] += arr[i - 1];
    }

    for(int i = 1; i <= tam; i += 2){
        pair<long long, long long> a, b;
        a = {arr[i - 1], arr[i]};
        b = {arr[tam] - arr[i], arr[tam] - arr[i - 1]};

        if(b < a) swap(a, b);

        if(a.second < b.first) continue;

        cout << a.second - b.first << '\n';
        return 0;
    }
    cout << "0\n";
}