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
    stack<int> A, B;
    set<int> numsA;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        A.push(x);
        numsA.insert(x);
    }

    vector<pair<char, char>> ans;
    int cur = 1;
    bool ok = true;
    for(int cur = 1; cur <= n; ++cur){
        if(numsA.count(cur)){
            while(A.top() != cur){
                B.push(A.top());
                numsA.erase(A.top());
                A.pop();
                ans.push_back({'A', 'B'});
            }

            ans.push_back({'A', 'C'});
            numsA.erase(A.top());
            A.pop();
        } else if(B.size() && B.top() == cur){
            ans.push_back({'B', 'C'});
            B.pop();
        } else {
            ok = false;
            break;
        }
    }

    if(ok){
        cout << ans.size() << '\n';
        for(auto [from, to] : ans) cout << from << ' ' << to << '\n';
    } else cout << "-1\n";
}
