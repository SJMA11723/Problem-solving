/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
* LinkedIn: https://www.linkedin.com/in/jorgetzab/
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        priority_queue<int> pending;
        priority_queue<int> q;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            q.push(arr[i]);
        }

        for(int i = 0; i < n; ++i){
            pending.push(arr[i]);
            while(pending.size() && pending.top() == q.top()){
                pending.pop();
                q.pop();
            }
            cout << arr[i] - q.top() << ' ';
            q.push(arr[i]);
        }
        cout << '\n';
    }
}
