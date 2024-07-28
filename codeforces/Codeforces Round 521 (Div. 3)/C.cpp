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
    int arr[n];
    int64_t sum = 0, maxi = 0, maxi2 = 0;
    for(int &x : arr){
        cin >> x;
        sum += x;

        if(x >= maxi){
            maxi2 = maxi;
            maxi = x;
        } else if(x > maxi2) maxi2 = x;
    }

    vector<int> ans;
    for(int i = 0; i < n; ++i){
        if(arr[i] == maxi){
            if(sum - arr[i] == 2*maxi2) ans.push_back(i + 1);
        } else if(sum - arr[i] == 2*maxi) ans.push_back(i + 1);
    }

    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i) cout << ans[i] << " \n"[i + 1 == ans.size()];
}
