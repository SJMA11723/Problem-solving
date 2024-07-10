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
    int ans[n] = {}, arr[n];
    map<int, int> last;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        int x = arr[i];
        if(last.count(x - 1)) ans[i] = ans[last[x - 1]] + 1;
        else ans[i] = 1;
        last[x] = i;
    }
    int *maxi = max_element(ans, ans + n);
    cout << *maxi << '\n';
    int first = arr[maxi - ans] - *maxi + 1;
    for(int i = 0; i < n; ++i)
        if(first == arr[i]) first++, cout << i + 1 << " \n"[i + 1 == n];
}
