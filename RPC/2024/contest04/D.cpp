#include <bits/stdc++.h>

using namespace std;

bool is_vowel(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string A, B; cin >> A >> B;
    int idx1 = 1;
    while(idx1 < A.size() && !is_vowel(A[idx1])) idx1++;

    int idx2 = (int)B.size() - 2;
    while(idx2 >= 0 && !is_vowel(B[idx2])) idx2--;

    if(idx2 >= 0) cout << A.substr(0, idx1) + B[idx2] + B.substr(idx2 + 1);
    else if(idx1 < A.size()) cout << A.substr(0, idx1) + A[idx1] + B.substr(idx2 + 1);
    else cout << A + 'o' + B;
    cout << '\n';
}
