/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 1500

using namespace std;

const int INF = 1e9;

int gauss (vector < bitset<MAXN + 1> > A, int n, int m, bitset<MAXN + 1> & ans) {
    vector<int> where (m, -1);
    for (int col = 0, row = 0; col < m && row < n; ++col) {
        for (int i = row; i < n; ++i)
            if (A[i][col]) {
                swap (A[i], A[row]);
                break;
            }
        if (! A[row][col])
            continue;
        where[col] = row;

        for (int i = 0; i < n; ++i)
            if (i != row && A[i][col])
                A[i] ^= A[row];
        ++row;
    }

    ans.reset();
    for (int i = 0; i < m; ++i)
        ans[i] = where[i] == -1 ? 1 : ((A[where[i]].count() ^ 1) & 1);

    for (int i = 0; i < m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    vector<bitset<MAXN + 1>> A(k + 1);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < k; ++j){
            char c; cin >> c;
            A[j][i] = c - '0';
        }
        A[k][i] = 1;
    }

    bitset<MAXN + 1> ans;
    int cnt_sol = gauss(A, k + 1, n, ans);
    if(ans.count()){
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(ans[i]) cout << (2 * cnt++ < ans.count() ? '1' : '2');
            else cout << '0';
        }
        cout << '\n';
    } else cout << "*\n";
}
