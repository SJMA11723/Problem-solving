#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first 
#define se second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    cin.ignore();

    for(int x = 0; x < n; x++){
        string line;
        getline(cin, line);
        //cout<<line<<"\n";
        string tmp;
        vector<string> tokens;
        for(int i = 0; i < line.length(); i++){
            if(line[i] == ' '){
                tokens.push_back(tmp);
                tmp = "";
            }
            else{
                tmp.push_back(line[i]);
            }
        }
        tokens.push_back(tmp);

        for(int i = 0; i < tokens.size(); i++){
            auto token = tokens[i];
            bool num = true;
            for(auto c : token){
                if(!(c >= '0' && c<= '9')) num = false;
            }
            if(!num) continue;
            int j;
            string lhs, rhs;
            for(j = token.length()-1; j>= 0; j--){
                if(token[j] != '0') break;
                rhs.push_back(token[j]);
            }

            for(; j>=0; j--){
                lhs.push_back(token[j]);
            }
            
            reverse(all(lhs));
            reverse(all(rhs));

            //cout<<lhs<<" " <<rhs<<"\n";

            int nz = rhs.length();
            if(nz < 4) continue;
            string base = " ";
            base[0] = lhs[0];
            string dec;
            for(int j = 1; j < lhs.length(); j++){
                dec.push_back(lhs[j]);
            }

            //cout<<base<<" fuckthat "<<dec<<"\n";

            
            nz+= dec.length();
            string prev;
            if(lhs.length() == 1) prev = base;
            else prev = base + "." +dec;
            if(lhs == "1") tokens[i] = "10^{"+to_string(nz)+"}";
            else tokens[i] = prev + "\\cdot10^{"+to_string(nz)+"}";
        }

        for(int i = 0; i < tokens.size(); i++){
            if(i != tokens.size()-1) cout<<tokens[i]<<" ";
            else cout<<tokens[i]<<"\n";
        }
    }


}