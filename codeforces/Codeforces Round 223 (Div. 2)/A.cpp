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

    int sereja = 0, dima = 0;
    for(int i = 0; i < n; ++i){
        if(i % 2){
            if(arr.front() > arr.back()){
                dima += arr.front();
                arr.pop_front();
            } else {
                dima += arr.back();
                arr.pop_back();
            }
        } else {
            if(arr.front() > arr.back()){
                sereja += arr.front();
                arr.pop_front();
            } else {
                sereja += arr.back();
                arr.pop_back();
            }
        }
    }

    cout << sereja << ' ' << dima << '\n';
}
