/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXVAL 200000

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int cub[MAXVAL + 1] = {};
    int arr[n], idx_max = 0;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        cub[arr[i]]++;
        if(cub[arr[i]] > cub[arr[idx_max]]) idx_max = i;
    }

    cout << n - cub[arr[idx_max]] << '\n';
    for(int i = idx_max + 1; i < n; ++i){
        if(arr[i] > arr[idx_max]) cout << "2 " << i + 1 << ' ' << i << '\n';
        else if(arr[i] < arr[idx_max]) cout << "1 " << i + 1 << ' ' << i << '\n';
    }

    for(int i = idx_max - 1; 0 <= i; --i){
        if(arr[i] > arr[idx_max]) cout << "2 " << i + 1 << ' ' << i + 2 << '\n';
        else if(arr[i] < arr[idx_max]) cout << "1 " << i + 1 << ' ' << i + 2 << '\n';
    }
}
