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
        int n; cin >> n;
        pair<string, int> arr[n];
        string words[n];
        for(int i = 0; i < n; ++i){
            string str; cin >> str;
            arr[i] = {str, i};
            words[i] = str;
        }
        sort(arr, arr + n);
        sort(words, words + n);
        string ans(n, '0');

        for(int i = 0; i < n; ++i){
            string s = arr[i].first;
            for(int j = 0; j < s.size(); ++j){
                string l = s.substr(0, j + 1);
                string r = s.substr(j + 1);

                if(binary_search(words, words + n, l) && binary_search(words, words + n, r)){
                    ans[ arr[i].second ]  = '1';
                    break;
                }
            }
        }

        cout << ans << '\n';
    }
}
