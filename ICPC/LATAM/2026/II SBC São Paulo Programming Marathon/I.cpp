#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

const int MOD = 1e9 + 7;

set<string> ans;
string num, s;

void generate(int i = 0, int j = 0){
    if(i == 11){
        if(j < sz(s)) return;
        ans.insert(num);
        return;
    }
    
    if(i == 0){
        if(11 - i == sz(s) - j){
            // obligado a usar s[j]
            if(s[j] != '1') return;
            
            num += s[j];
            generate(i + 1, j + 1);
            num.pop_back();
        } else {
            // falla teclado uso 1
            num += '1';
            generate(i + 1, j);
            num.pop_back();

            // uso s[j] si es 1
            if(j < sz(s) && s[j] == '1'){
                num += s[j];
                generate(i + 1, j + 1);
                num.pop_back();
            }
        }
        return;
    } else if(i == 1){
        // num[i] tiene que > 0
        if(11 - i == sz(s) - j){
            // obligado a usar s[j]
            if(s[j] == '0') return;

            num += s[j];
            generate(i + 1, j + 1);
            num.pop_back();
        } else {
            // falla teclado uso 1
            num += '1';
            generate(i + 1, j);
            num.pop_back();

            // falla teclado uso 9
            num += '9';
            generate(i + 1, j);
            num.pop_back();

            // si s[j] > 0 podemos usar digito de s
            if(j < sz(s) && s[j] != '0'){
                num += s[j];
                generate(i + 1, j + 1);
                num.pop_back();
            }
        }
    } else if(i == 2){
        // num[i] tiene que ser 9
        if(11 - i == sz(s) - j){
            // obligado a usar s[j]
            if(s[j] != '9') return;
            num += s[j];
            generate(i + 1, j + 1);
            num.pop_back();
        } else {
            // falla teclado uso 9
            num += '9';
            generate(i + 1, j);
            num.pop_back();

            // si s[j] = 9 podemos usar digito de s
            if(j < sz(s) && s[j] == '9'){
                num += s[j];
                generate(i + 1, j + 1);
                num.pop_back();
            }
        }
    } else {
        if(11 - i == sz(s) - j){
            // obligado a usar s[j]
            num += s[j];
            generate(i + 1, j + 1);
            num.pop_back();
        } else {
            // falla teclado uso 1
            num += '1';
            generate(i + 1, j);
            num.pop_back();

            // falla teclado uso 9
            num += '9';
            generate(i + 1, j);
            num.pop_back();

            // podemos usar digito de s
            if(j < sz(s)){
                num += s[j];
                generate(i + 1, j + 1);
                num.pop_back();
            }
        }

        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    if(sz(s) > 11){
        cout << "0\n";
        return 0;
    }

    generate();
    cout << sz(ans) << '\n';
    for(string n : ans) cout << n << '\n';
}