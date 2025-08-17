#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;cin >> n;
    vi a(n);
    for( int &x: a) cin  >> x;

    // contar los valores utiles
    vi valores = {2,4,8,269,538,1076,2152,7487};
    map<int,int> freq;


    for( int x : a ){
        if( x==2||x==4||x==8||x==269||x==538||x==1076||x==2152||x==7487 ) ++freq[x];
    }

    // siembre debe haber un 7487
    if(  freq[7487] == 0  ){
        cout << "0\n";
        return 0;
    }


    vi ans;
    ans.push_back(7487);

    ///  2*2*2 // 269
    if( freq[269] >= 1 && freq[2] >= 3  ){
        ans.push_back(269);
        ans.push_back(2);
        ans.push_back(2);
        ans.push_back(2);
    }
    else  if( freq[269] >= 1 && freq[4] >= 1 && freq[2] >= 1 ){
        ans.push_back(269);
        ans.push_back(4);
        ans.push_back(2);
    }
    else  if(  freq[269] >= 1 && freq[8] >= 1  ){
        ans.push_back(269);
        ans.push_back(8);
    }
    ///  2*2 // 538
    else if( freq[2*269] >= 1  && freq[2] >= 2  ){
        ans.push_back(538);
        ans.push_back(2);
        ans.push_back(2);
    }
    else  if( freq[2*269] >= 1  && freq[4] >= 1   ){
        ans.push_back(538);
        ans.push_back(4);
    }
    /// 2 // 1076
    else if( freq[4*269] >= 1&& freq[2] >= 1  ){
        ans.push_back(1076);
        ans.push_back(2);
    }
    // no hace falta bsucar
    else if( freq[8*269] >= 1 ){ //2152
        ans.push_back(2152);
    }
    // nignuno se pudo
    else{
        cout << "0\n";
        return 0;
    }

    cout << ans.size() << '\n';
    for( int i=0; i<ans.size(); i++){
        cout <<  ans[i] << " \n"[i==ans.size()-1];
    }



}
