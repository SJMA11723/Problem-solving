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
    string s; cin >> s;
    char colors[3] = {'B', 'G', 'R'};
    int cnt_ans = INT_MAX;
    string s_ans;

    do{
        int cnt = 0;
        string res = s;
        for(int i = 0; i < n; ++i){
            if(res[i] != colors[i % 3]){
                cnt++;
                res[i] = colors[i % 3];
            }
        }
        if(cnt < cnt_ans){
            cnt_ans = cnt;
            s_ans = res;
        }
    }while(next_permutation(colors, colors + 3));


    cout << cnt_ans << '\n' << s_ans << '\n';
}
