#include <bits/stdc++.h>
#define lsb(n) ((n) & -(n))

using namespace std;

bool gana(vector<int> &A, vector<int> &B, bool turn = true, int cnt = 0){
    if(A.size() == 1) return (A[0] < B[0]) + cnt >= 2 && (A[0] < B[1]) + cnt >= 2;

    int n = A.size(), m = B.size();
    bool res = false;
    //cout << "---\n";
    for(int i = 0; i < n; ++i){
        int a = A[i];
        A.erase(A.begin() + i);
        bool ok = true;
        //cout << "a: " << a << '\n';
        for(int j = 0; j < m; ++j){
            int b = B[j];
            B.erase(B.begin() + j);

            ok &= gana(A, B, a < b, cnt + (a < b));

            B.insert(B.begin() + j, b);
        }
        A.insert(A.begin() + i, a);
        res |= ok;
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> A, B;
    for(int i = 0; i < 3; ++i){
        int x; cin >> x;
        A.push_back(x);
    }
    for(int i = 1; i <= 7; ++i)
    if(i != A[0] && i != A[1] && i != A[2]) B.push_back(i);

    cout << (gana(A, B) ? "S\n" : "N\n");
}
