/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;
    int cnt = 0;
    int arr[n], pos[n];
    cin >> arr[0]; arr[0]--;
    pos[arr[0]] = 0;
    for(int i = 1; i < n; ++i){
        cin >> arr[i]; arr[i]--;
        pos[arr[i]] = i;
        if(arr[i - 1] > arr[i]) cnt++;
    }

    while(q--){
        int x, y; cin >> x >> y;
        x--, y--;
        int i = pos[x], j = pos[y];

        if(j < i){
            swap(i, j);
            swap(x, y);
        }

        if(i && arr[i - 1] > arr[i]) cnt--;
        if(i + 1 < n && arr[i] > arr[i + 1]) cnt--;
        if(i + 1 < j && j && arr[j - 1] > arr[j]) cnt--;
        if(j + 1 < n && arr[j] > arr[j + 1]) cnt--;

        swap(arr[i], arr[j]);
        pos[x] = j;
        pos[y] = i;

        if(i && arr[i - 1] > arr[i]) cnt++;
        if(i + 1 < n && arr[i] > arr[i + 1]) cnt++;
        if(i + 1 < j && j && arr[j - 1] > arr[j]) cnt++;
        if(j + 1 < n && arr[j] > arr[j + 1]) cnt++;

        if(!cnt || (cnt == 1 && arr[0] > arr[n - 1])) cout << "DA\n";
        else cout << "NE\n";
    }
}
