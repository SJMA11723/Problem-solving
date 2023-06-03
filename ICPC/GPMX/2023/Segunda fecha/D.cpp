#include <bits/stdc++.h>

using namespace std;

string inToString(long long x){
    if(x == 0) return "0";

    string num;
    int tmp = abs(x);
    while(tmp){
        num += char(tmp % 10 + '0');
        tmp /= 10;
    }
    if(x < 0) num += '-';
    reverse(num.begin(), num.end());
    return num;
}

vector<int> prefix(string &s){
    int n = (int)s.size();
    vector<int> pi(n);
    for(int i = 1; i < n; ++i){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) j = pi[j - 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> m >> n;

    string difM, difN;
    int ant; cin >> ant;
    for(int i = 1; i < m; ++i){
        int x; cin >> x;
        difM += "|" + inToString(x - ant) + "|";
        ant = x;
    }
    cin >> ant;
    for(int i = 1; i < n; ++i){
        int x; cin >> x;
        difN += "|" + inToString(x - ant) + "|";
        ant = x;
    }

    if(m == 1){
        cout << n << '\n';
        return 0;
    }

    //cout << difM << '\n' << difN << '\n';

    string str = difM + "#" + difN;
    vector<int> pi = prefix(str);

    int ans = 0;
    for(int it : pi){
        if(it == difM.size()) ans++;
    }
    cout << ans << '\n';

    return 0;
}
