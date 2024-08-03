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
    int n; cin >> n;
    deque<int> indices;
    int arr[n], cnt = 1, prv = INT_MAX;
    int L[n], R[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        indices.push_back(i);

        if(prv > arr[i]) cnt++;
        else cnt = 1;
        R[i] = cnt;
        prv = arr[i];
    }

    prv = INT_MAX;
    for(int i = n - 1; 0 <= i; --i){
        if(prv > arr[i]) cnt++;
        else cnt = 1;
        L[i] = cnt;
        prv = arr[i];
    }

    prv = 0;
    string ans;
    while(indices.size() && (arr[indices.front()] > prv || arr[indices.back()] > prv)){
        int l = indices.front(), r = indices.back();
        if(prv < arr[l] && prv < arr[r]){
            if(arr[l] < arr[r] || (arr[l] == arr[r] && L[l] >= R[r])){
                ans += "L";
                prv = arr[l];
                indices.pop_front();
            } else if(arr[r] < arr[l] || (arr[l] == arr[r] && L[l] <= R[r])){
                ans += "R";
                prv = arr[r];
                indices.pop_back();
            }
        } else if(prv < arr[l]){
            ans += "L";
            prv = arr[l];
            indices.pop_front();
        } else {
            ans += "R";
            prv = arr[r];
            indices.pop_back();
        }
    }

    cout << ans.size() << '\n' << ans << '\n';
}
