#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef vector<vector<int>> vvi;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()
#define INF 10000000
#define lsb(S) ((S) & -(S))
#define DEBUG if (debb)

bool debb = false;

template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
  return os << '(' << p.fi << ", " << p.se << ')';
}
template <typename C,
          typename T = typename enable_if<!is_same<C, string>::value,
                                          typename C::value_type>::type>
ostream& operator<<(ostream& os, const C& v) {
  string sep;
  for (const T& xx : v)
    os << sep << xx, sep = " ";
  return os;
}
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args&&... values) {
  cout << "[Debug]\n\t" << vars << " = ";
  string d = "[";
  (..., (cout << d << values, d = "] ["));
  cout << "]\n";
}


bool isdigit(string& s, int i){
    bool idig = (s[i] >= '0' && s[i] <= '9');
    return idig;
}

bool validator(string& s){
    bool ppos = true;
    vector<pair<string, ll>> lhs;
    vector<pair<string, ll>> rhs;
    string news = s + '+'; 
    int sz = news.length();
    bool lhst = true;
    string tmp = "";
    ll lhsum = 0, rhsum = 0;
    for(int i = 0; i < sz; i++){
        if((tmp.size() > 1 && tmp[0] == '0') || tmp.size()> 10){
            DEBUG deb("ass");
            return 0;
        }
        if(news[i] >= '0' && news[i] <= '9'){
            tmp.push_back(news[i]);
        }
        else{
            ll num;
            if(tmp == "") {
                DEBUG deb("ass");
                return false;
            }
            else num = stoll(tmp);
            if(!ppos) num*=-1;
            if(lhst){
                lhsum+=num;
                lhs.pb({tmp, num});
            }
            else{
                rhsum+=num;
                rhs.pb({tmp, num});
            }
            tmp = "";
            if(news[i] == '+') ppos = true;
            else if(news[i] == '-') ppos = false;
            else {
                ppos = true;
                lhst = false;
            }
        }
        
    }
   DEBUG deb(lhs);
   DEBUG deb(rhs);
    return lhsum == rhsum;
    
}
int main() {
  if (!debb)
    ios_base::sync_with_stdio(false);
  if (!debb)
    cin.tie(0);
    string s;
    cin>>s;

    if(validator(s)){
        cout<<"Correct\n";
        return 0;
    }
    for(int i = 0; i < s.length(); i++){
        for(int j = 0; j < s.length(); j++){
            
            if(!(i != j && isdigit(s,i))) continue;
            DEBUG deb(i,j);
            string tmp = s;
            char c = s[i];
            if(i < j){
                tmp.erase(tmp.begin()+i);
                tmp.insert(tmp.begin()+(j-1), c);
            }
            else{
                tmp.erase(tmp.begin()+i);
                tmp.insert(tmp.begin()+j, c);
            }
            DEBUG deb(tmp);
            if(validator(tmp)){
                cout<<tmp<<"\n";
                return 0;
            }
        }
    }

    cout<<"Impossible\n";
    


}