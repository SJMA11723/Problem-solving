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
        int m, x; cin >> m >> x;

        priority_queue<int> cost;
        int ans = 0, pounds = 0;
        for(int i = 1; i <= m; ++i){
            int c; cin >> c;

            if(pounds >= c){
                pounds -= c;
                cost.push(c);
            } else if(cost.size()){
                int maxi = cost.top();
                cost.pop();
                pounds += maxi;

                pounds -= min(c, maxi);
                cost.push(min(c, maxi));
            }

            pounds += x;
        }

        cout << cost.size() << '\n';
    }
}
