/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct sparse_table{
    int n, NEUTRO;
    vector<vector<int>> ST;
    vector<int> lg2;
    int f(int a, int b){return max(a, b);}

    sparse_table(int _n, int data[]){
        n = _n;
        NEUTRO = 0;
        lg2.resize(n + 1);
        lg2[1] = 0;
        for(int i = 2; i <= n; ++i) lg2[i] = lg2[i / 2] + 1;
        ST.resize(lg2[n] + 1, vector<int>(n + 1, NEUTRO));
        for(int i = 0; i < n; ++i) ST[0][i] = data[i];
        for(int k = 1; k <= lg2[n]; ++k){
            int fin = (1 << k) - 1;
            for(int i = 0; i + fin < n; ++i)
                ST[k][i] = f(ST[k - 1][i], ST[k - 1][i + (1 << (k - 1))]);
        }
    }

    int query(int l, int r){
        if(l > r) return NEUTRO;
        int lg = lg2[r - l + 1];
        return f(ST[lg][l], ST[lg][r - (1 << lg) + 1]);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int &x : arr) cin >> x;

    sparse_table ST(n, arr);

    int q; cin >> q;
    while(q--){
        int m; cin >> m;
        vector<int> A;

        for(int i = 0; i < m; ++i){
            int idx; cin >> idx; idx--;
            if(A.size()){
                //cout << A.back() << ' ' << idx << endl;
                //cout << ST.query(A.back(), idx) << endl;
                A.push_back(ST.query(A.back(), idx));
            }
            A.push_back(idx);
        }

        m = A.size();

        for(int i = 0; i < m; i += 2) A[i] = arr[A[i]];

        //cout << m << '\n';
        //for(int x : A) cout << x << ' ';
        //cout << endl;

        int L[m], R[m];
        stack<int> st;
        for(int i = 0; i < m; ++i){
            while(st.size() && A[st.top()] < A[i]){
                R[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        while(st.size()){
            R[st.top()] = m;
            st.pop();
        }

        for(int i = m - 1; 0 <= i; --i){
            while(st.size() && A[st.top()] <= A[i]){
                L[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        while(st.size()){
            L[st.top()] = -1;
            st.pop();
        }

        uint64_t ans = 0;
        for(int i = 0; i < m; ++i){
            ans += 1ull * A[i] * ((i + 2) / 2 - (L[i] + 2) / 2) * ((R[i] - 1 + 2) / 2 - (i - 1 + 2) / 2);
        }
        cout << ans << '\n';
    }
}
