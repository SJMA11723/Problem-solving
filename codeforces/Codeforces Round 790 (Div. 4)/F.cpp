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
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        map<int, int> cub;
        while(n--){
            int x; cin >> x;
            cub[x]++;
        }

        vector<int> arr; arr.reserve(cub.size());
        for(auto &it : cub) if(it.second >= k) arr.push_back(it.first);
        if(arr.size() == 0){
            cout << "-1\n";
            continue;
        }

        int L = arr[0], R = L, ant = L;
        for(int i = 1; i < arr.size(); ++i){
            if(arr[i] - 1 != arr[i - 1]){
                if(arr[i - 1] - ant > R - L){
                    L = ant;
                    R = arr[i - 1];
                }
                ant = arr[i];
            } else if(i + 1 == arr.size() && arr[i] - ant > R - L){
                L = ant;
                R = arr[i];
            }
        }
        cout << L << ' ' << R << '\n';
    }
}
