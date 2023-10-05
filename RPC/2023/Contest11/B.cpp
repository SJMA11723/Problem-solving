/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct customer{
    int id, arrival, time, patience;
    bool operator<(const customer &b){
        return arrival < b.arrival;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    customer arr[n];
    for(int i = 0; i < n; ++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        arr[i] = customer{a, b, c, d};
    }
    sort(arr, arr + n);
    int time = 0;
    for(int i = 0; i < n; ++i){
        if(time <= arr[i].arrival){
            time = arr[i].arrival + arr[i].time;
            cout << arr[i].id << '\n';
        } else if(time <= arr[i].arrival + arr[i].patience){
            time += arr[i].time;
            cout << arr[i].id << '\n';
        }
    }
}
