#include<bits/stdc++.h>

using namespace std;

int64_t val(char c){
    if(c == 'I') return 1;
    if(c == 'V') return 5;
    if(c == 'X') return 10;
    if(c == 'L') return 50;
    if(c == 'C') return 100;
    if(c == 'D') return 500;
    return 1000;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    while(n--){
        string s; cin >> s;
        int64_t ans = 0;
        set<int> nums;
        for(int i = (int)s.size() - 1; 0 <= i; --i){
            if(nums.upper_bound(val(s[i])) != nums.end())
                ans -= val(s[i]);
            else
                ans += val(s[i]);
            nums.insert(val(s[i]));
        }
        cout << ans << '\n';
    }
}
