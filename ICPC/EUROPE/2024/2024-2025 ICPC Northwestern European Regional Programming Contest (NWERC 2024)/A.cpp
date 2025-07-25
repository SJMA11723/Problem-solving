#/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const ll MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    cin.ignore();
    pair<string, string> arr[n];
    for(int i = 0; i < n; ++i){
        string s;
        getline(cin, s);
        arr[i].se = s;
        for(int j = 0; j < sz(s); ++j){
            if('A' <= s[j] && s[j] <= 'Z'){
                arr[i].fi = s.substr(j);
                break;
            }
        }
    }
    sort(arr, arr + n);
    for(int i = 0; i < n; ++i){
        cout << arr[i].se << '\n';
    }
}
