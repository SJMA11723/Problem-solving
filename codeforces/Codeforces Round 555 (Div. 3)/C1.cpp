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
    deque<int> arr;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        arr.push_back(x);
    }

    int prv = 0;
    string ans;
    while(arr.size() && (arr.front() > prv || arr.back() > prv)){
        if(prv < arr.front() && prv < arr.back()){
            if(arr.front() < arr.back()){
                ans += "L";
                prv = arr.front();
                arr.pop_front();
            } else {
                ans += "R";
                prv = arr.back();
                arr.pop_back();
            }
        } else if(prv < arr.front()){
            ans += "L";
            prv = arr.front();
            arr.pop_front();
        } else {
            ans += "R";
            prv = arr.back();
            arr.pop_back();
        }
    }

    cout << ans.size() << '\n' << ans << '\n';
}
